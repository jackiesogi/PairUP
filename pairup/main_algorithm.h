#include "Windows.h"
#include <jck\include\c++\x86_64-w64-mingw32\bits\stdc++.h>
#include <codecvt>
#include <msclr\marshal_cppstd.h>
#include <jck\unordered_map>
#define MAX_MEMBER 100

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace msclr::interop;

namespace startPair {

	//Global variables declaration
	int priority[MAX_MEMBER] = { 0 };						//分數of優先配對順序，考量"填入時段數"及"成員配合度"(之後會考慮加上權重)。
	short want_times[MAX_MEMBER];							//數字of每個人在那張google sheet上所填的想練習次數。(註:若同一個人同時有填一次和兩次，以兩次優先)。
	short want_times_copy[MAX_MEMBER];						//備份ofwant_times[50]。因為Permutation時want_times[50]會隨著已經配對，而次數減少；所以在每次新的排列時，都要從want_times_copy[50]再copy一份。
	std::vector<std::wstring> pple_whofill;			//名單of有填要練習的成員。
	std::vector<std::wstring> pple_whofinish;		//名單of完成配對的成員(只要有一組人被配對完成，就會被加進來)。
	std::vector<std::wstring> pple_not_paired;		//名單of沒被配對到的成員(在排列計算中，每一次的最後會將"有填要練習的成員"減去"完成配對的成員"，得到結果)。
	int AmountOfMemberFillin = 0;					//數字of這張google sheet上有填要練習的人數(不管一次還是兩次)。
	std::vector<std::wstring> available_list[MAX_MEMBER];	//每個人可能配對到的成員組合。 
	std::wstring RESULT = L"";
	std::wstring MIN_RESULT = L"";
	short amount_not_paired = 0;
	short min_amount_not_paired = 99;
	int swap_count = 0;
	int swap_random_seed;
	short table[MAX_MEMBER][15] = { 0 };
	const int N = 2e+5;
	int n, m, h[N], e[N], ne[N], match[N];
	bool st[N];
	int ROW_OF_TABLE = 1;
	int COL_OF_TABLE = 1;
	std::unordered_map <std::wstring, int > umap;


	inline std::wstring get_member(int id) {
		for (auto it = umap.begin(); it != umap.end(); ++it) {
			if (it->second == id) return it->first;
		}
	}

	inline int get_id(std::wstring member) {
		return umap.at(member);
	}

	inline std::wstring get_time(short r) {
		switch (r) {
		case 0:  return L" (1700~1730)";
		case 1:  return L" (1730~1800)";
		case 2:  return L" (1800~1830)";
		case 3:  return L" (1830~1900)";
		case 4:  return L" (1900~1930)";
		case 5:  return L" (1930~2000)";
		case 6:  return L" (2000~2030)";
		case 7:  return L" (2030~2100)";
		case 8:  return L" (2100~2130)";
		case 9:  return L" (2130~2200)";
		case 10: return L" (2200~2230)";
		case 11: return L" (2230~2300)";
		case 12: return L" (2300~2330)";
		case 13: return L" (2330~2400)";
		case 14: return L" (2400~2430)";
		}
	}

	void add(int a, int b, int idx) {
		e[idx] = b;
		ne[idx] = h[a];
		h[a] = idx;
	}

	bool find(int u) {
		for (int i = h[u]; i != -1; i = ne[i]) {
			int v = e[i];
			if (!st[v]) {
				st[v] = true;
				if (!match[v] || find(match[v])) {
					match[v] = u;
					return true;
				}
			}
		}
		return false;
	}

	inline void swapRows(std::vector<std::wstring> matrix[MAX_MEMBER], int i, int j) {

		std::vector<std::wstring> temp = matrix[i];
		matrix[i] = matrix[j];
		matrix[j] = temp;
	}

	inline bool member_finish_pair(short id) {
		want_times[id]--;
		if (want_times[id] <= 0) {
			if (want_times[id] == 0) {
				pple_whofinish.push_back(get_member(id));
			}
			return true;
		}
		else
			return false;
	}

	inline std::wstring find_range(short id1, short id2) {
		for (int i = 0; i < 15; i++) {
			if (table[id1][i] > 0) {
				if (table[id2][i] > 0) {
					return get_time(i);
				}
			}
		}
	}

	void generatePermutations(std::vector<std::wstring> matrix[MAX_MEMBER], int start) {

		if (start == AmountOfMemberFillin) {

			for (int i = 0; i < ROW_OF_TABLE - 2; i++) {
				want_times[i] = want_times_copy[i];
			}
			pple_not_paired.clear();
			pple_whofinish.clear();

			RESULT = L"Enjoy chatting with your partner\r\n";

			bool visit[MAX_MEMBER] = { false };
			for (int i = 0; i < ROW_OF_TABLE - 2; i++) {
				for (int j = 1; j < available_list[i].size(); j++) {

					if (!visit[get_id(available_list[i][j])] && !visit[get_id(available_list[i][0])]) {

						RESULT += (available_list[i][0] + L" <--> " + available_list[i][j]);

						if (member_finish_pair(get_id(available_list[i][0])))
							visit[get_id(available_list[i][0])] = true;
						if (member_finish_pair(get_id(available_list[i][j])))
							visit[get_id(available_list[i][j])] = true;

						RESULT += (find_range(get_id(available_list[i][0]), get_id(available_list[i][j])) + L"\r\n");

						break;
					}
				}
			}

			sort(pple_whofinish.begin(), pple_whofinish.end());
			for (std::wstring& i : pple_whofill) {
				if (!binary_search(pple_whofinish.begin(), pple_whofinish.end(), i)) {
					pple_not_paired.push_back(i);
				}
			}

			RESULT += L"As for \r\n";

			for (int i = 0; i < pple_not_paired.size(); i++) {
				RESULT += (pple_not_paired[i] + L"\r\n");
			}
			RESULT += (L"you can choose to \r\n1) take a day off(count out)\r\n2) requesting for partners\r\n3) leave a 4 - minute up voice message and answer questions related to weekly topic.ONLY on Monday can talk about your last weekend or sharing something interesting.\r\n");

			amount_not_paired = pple_not_paired.size();
			if (amount_not_paired < min_amount_not_paired) {
				min_amount_not_paired = amount_not_paired;
				MIN_RESULT = RESULT;
				swap_count++;
			}
			else if (amount_not_paired == min_amount_not_paired && swap_count < swap_random_seed) {
				min_amount_not_paired = amount_not_paired;
				MIN_RESULT = RESULT;
				swap_count++;
			}

			return;
		}

		for (int i = start; i < AmountOfMemberFillin; i++) {
			swapRows(matrix, start, i);
			generatePermutations(matrix, start + 1);
			swapRows(matrix, start, i);
		}
	}

	void BubbleSort() {
		int n = ROW_OF_TABLE - 2;
		for (int i = n - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (priority[j] < priority[j + 1]) {
					//swap number
					std::swap(priority[j], priority[j + 1]);
					//swap address
					available_list[j].swap(available_list[j + 1]);
				}
			}
		}
	}


	long int jie_cheng(short num) {
		int mult = 1;
		for (int i = 1; i < num; i++) {
			mult *= i;
		}
		return mult;
	}

	bool cmp(std::wstring a, std::wstring b) {
		return get_id(a) < get_id(b);
	}

	void av_BubbleSort() {
		for (int i = 0; i < ROW_OF_TABLE - 2; i++) {
			std::sort(available_list[i].begin() + 1, available_list[i].end(), cmp);
		}
	}


	void large_scale_algo() {

		MIN_RESULT = L"Enjoy chatting with your partner\r\n";

		memset(h, -1, sizeof h);
		int idx = 0;
		n = ROW_OF_TABLE - 2;
		av_BubbleSort();
		int len;
		for (int i = 0; i < AmountOfMemberFillin; i++) {
			len = available_list[i].size();
			for (int j = 0; j < len; j++) {
				add(get_id(available_list[i][0]), get_id(available_list[i][j]), idx);
				idx++;
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			memset(st, 0, sizeof st);
			if (find(i)) cnt++;
		}

		for (int i = 0; i < n; i++) {
			if (match[i]) {
				if (want_times[i] > 0 && want_times[match[i]] > 0) {
					MIN_RESULT += (get_member(i) + L"<--->" + get_member(match[i]) + find_range(i, match[i]) + L"\r\n");
					want_times[i]--;
					want_times[match[i]]--;
					match[match[i]] = i;

				}
			}
		}
		MIN_RESULT += L"As for:\r\n";
		for (int i = 0; i < n; i++) {
			if (want_times[i] > 0) {
				//match[i] = u;
				MIN_RESULT += (get_member(i) + L"\r\n");
			}
		}
		MIN_RESULT += (L"you can choose to \r\n1) take a day off(count out)\r\n2) requesting for partners\r\n3) leave a 4 - minute up voice message and answer questions related to weekly topic.ONLY on Monday can talk about your last weekend or sharing something interesting.\r\n");

	}

	void large_scale_algo2() {

		int r = (rand() % 4000 - 2000);

		for (int i = 0; i < 8000 + r; i++) {

			RESULT = L"Enjoy chatting with your partner\r\n";

			bool visit[MAX_MEMBER] = { false };
			for (int i = 0; i < ROW_OF_TABLE - 2; i++) {
				for (int j = 1; j < available_list[i].size(); j++) {

					if (!visit[get_id(available_list[i][j])] && !visit[get_id(available_list[i][0])]) {


						RESULT += (available_list[i][0] + L" <--> " + available_list[i][j]);

						if (member_finish_pair(get_id(available_list[i][0])))
							visit[get_id(available_list[i][0])] = true;
						if (member_finish_pair(get_id(available_list[i][j])))
							visit[get_id(available_list[i][j])] = true;

						//
						RESULT += (find_range(get_id(available_list[i][0]), get_id(available_list[i][j])) + L"\r\n");
						//

						break;
					}
				}
			}

			sort(pple_whofinish.begin(), pple_whofinish.end());
			for (std::wstring& i : pple_whofill) {
				if (!binary_search(pple_whofinish.begin(), pple_whofinish.end(), i)) {
					pple_not_paired.push_back(i);
				}
			}

			RESULT += L"As for \r\n";

			for (int i = 0; i < pple_not_paired.size(); i++) {
				RESULT += (pple_not_paired[i] + L"\r\n");
			}
			RESULT += (L"you can choose to \r\n1) take a day off(count out)\r\n2) requesting for partners\r\n3) leave a 4 - minute up voice message and answer questions related to weekly topic.ONLY on Monday can talk about your last weekend or sharing something interesting.\r\n");

			amount_not_paired = pple_not_paired.size();
			if (amount_not_paired < min_amount_not_paired) {
				min_amount_not_paired = amount_not_paired;
				MIN_RESULT = RESULT;
				swap_count++;
			}
		}

		return;
	}

	//pairing algorithm starts
	void show_pair() {

		BubbleSort();

		AmountOfMemberFillin = pple_whofill.size();

		//Decide which algorithm to use accordding to the amount of member filled in.
		if (AmountOfMemberFillin >= 8) {
			large_scale_algo2();
		}
		else {
			generatePermutations(available_list, 0);
		}
	}

	//The entry point of this header file.
	std::wstring main_algorithm(String^ Path) {

		//Convert the path to std::string
		std::string Data_path = marshal_as<std::string>(Path);
		//std::setlocale(LC_ALL, "en_US.utf8");

		//Initialize the variables when each time main_algorithm is called.
		AmountOfMemberFillin = 0;
		RESULT = L"";
		MIN_RESULT = L"";
		amount_not_paired = 0;
		min_amount_not_paired = 99;
		swap_count = 0;
		ROW_OF_TABLE = 1;
		COL_OF_TABLE = 1;

		for (int i = 0; i < MAX_MEMBER; i++) {
			available_list[i].clear();
			priority[i] = 0;
			want_times[i] = 0;
			want_times_copy[i] = 0;
		}
		pple_whofill.clear();
		pple_whofinish.clear();
		pple_not_paired.clear();
		umap.clear();



		//Randomness that will decide whether to replace the new output as the
		//final result when the amount_not_paired is the same.
		srand(time(NULL));
		swap_random_seed = rand() % 1000 + 1;


		//Read the csv file
		std::ifstream fin, fin2;
		fin.open(Data_path, std::ios::in);
		fin2.open(Data_path, std::ios::in);
		if (!fin) {
			MessageBox::Show("Could not read the file! Either the path is incorrect or the file is broken.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return L"";
		}
		else {

			std::string all = "";
			std::wstring data = L"";
			std::string line = "";
			std::string word = "";
			int length = 0;
			int count_row = 0;
			int count_col = 0;

			for (int i = 0; i < ROW_OF_TABLE - 2; i++)
				for (int j = 0; j < 15; j++)
					table[i][j] = 0;

			getline(fin2, line);
			std::istringstream iss(line);
			while (getline(iss, word, ',')) {
				COL_OF_TABLE++;
			}
			while (getline(fin2, line)) {
				ROW_OF_TABLE++;
			}

			std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
			//最初的 Excel raw data 
			while (getline(fin, all)) {
				std::wstring wall = converter.from_bytes(all);
				std::wstringstream wss(wall);

				for (int count_col = 0; count_col < COL_OF_TABLE; count_col++) {							//32*18 with 30*15

					std::getline(wss, data, L',');



					//Create a map of member and id
					if ((count_row >= 1 && count_row <= ROW_OF_TABLE - 2) && count_col == 0) {
						umap.insert(std::pair<std::wstring, int>(data, count_row - 1));
					}


					if ((count_row >= 1 && count_row <= ROW_OF_TABLE - 2) && (count_col >= 2 && COL_OF_TABLE - 2)) {
						if (data == L"") {
							table[count_row - 1][count_col - 2] = 0;
						}
						else if (data == L"V" || data == L"v" || data == L"1") {

							table[count_row - 1][count_col - 2] = 1;
							if (want_times[count_row - 1] < 1) {
								want_times[count_row - 1] = 1;	//times want to practice
							}
						}
						else if (data == L"2" || data == L"twice" || data == L"V*2" || data == L"v*2" || data == L"V(twice)"
							|| data == L"v(twice)" || data == L"Twice" || data == L"V(Twice)" || data == L"v(Twice)") {

							table[count_row - 1][count_col - 2] = 2;
							if (want_times[count_row - 1] < 2) {
								want_times[count_row - 1] = 2;
							}
						}

					}
				}
				count_row++;
			}



			//i,j (同一個人跑不同時段 true才停下來 : 檢查一個人可以的時段)
			//k,j (同個時段跑不同一人 true才停下來 : 檢查有哪些人可以配合)
			//#pragma omp parallel for
			for (int i = 0; i < ROW_OF_TABLE - 2; i++) {
				//避免同一個人出現在 available_list兩次 (因為有可能有一個以上可以配對的時段) 
				bool visit[MAX_MEMBER] = { false };
				available_list[i].push_back(get_member(i));
				for (int j = 0; j < 15; j++) {
					if (table[i][j]) {
						priority[i]++;
						for (int k = 0; k < ROW_OF_TABLE - 2; k++) {
							if (k == i) {}
							else if (table[k][j]) {
								if (!visit[k]) {
									priority[i]++;
									available_list[i].push_back(get_member(k));
									visit[k] = true;
								}
							}
						}
					}
				}
			}

			for (int id = 0; id < ROW_OF_TABLE - 2; id++) {
				if (priority[id] > 0)
					pple_whofill.push_back(get_member(id));
			}
			for (int i = 0; i < ROW_OF_TABLE - 2; i++) {
				want_times_copy[i] = want_times[i];
			}

			//印出每個人可能配對到的組合 
			show_pair();

			return MIN_RESULT;
		}
	}
}
