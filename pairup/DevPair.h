<<FILES_NOT_USED_IN_THIS_PROJECT>>
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include <queue> 
#define NUMBER 5
#include <string> 


//����o��i�H��۰�Ū�� 
std::string get_time(int id){
	switch(id){
		case 0:  return " (1700~1730)";
		case 1:  return " (1730~1800)";
		case 2:  return " (1800~1830)";
		case 3:  return " (1830~1900)";
		case 4:  return " (1900~1930)";
		case 5:  return " (1930~2000)";
		case 6:  return " (2000~2030)";
		case 7:  return " (2030~2100)";
		case 8:  return " (2100~2130)";
		case 9:  return " (2130~2200)";
		case 10: return " (2200~2230)";
		case 11: return " (2230~2300)";
		case 12: return " (2300~2330)";
		case 13: return " (2330~2400)";
		case 14: return " (2400~2430)";
	}
}

std::string get_member(int id){
	switch(id){
		case 0:   return "��p�� (Linda) (�N����)";
		case 1:   return "���ӿ�Andrew";
		case 2:   return "Chunjung";
		case 3:   return "Viola";
		case 4:   return "�p��";
		case 5:   return "���b��";
		case 6:   return "����� Anita";
		case 7:   return "Ray";
		case 8:   return "Max Weng";
		case 9:  return "�K (Christine)";
		case 10:  return "������";
		case 11:  return "Wan-Cih";
		case 12:  return "Amine";
		case 13:  return "ChiaoYa";
		case 14:  return "����";
		case 15:  return "Sophia Li";
		case 16:  return "Sara";
		case 17:  return "Eddie";
		case 18:  return "�L�®f Austin";
		case 19:  return "Joyce";
		case 20:  return "michelle";
		case 21:  return "Lily";
		case 22:  return "���{�g";
		case 23:  return "Katie";
		case 24:  return "�����N";
		case 25:  return "Sophia Yang";
		case 26:  return "Grace Lu";
		case 27:  return "Jane";
		case 28:  return "Avery";
		case 29:  return "Mia";
		default:  return "WRONG!!!";
	} 
}
int get_id(std::string member){
	if(member=="��p�� (Linda) (�N����)")	return 0;
	if(member=="���ӿ�Andrew")				return 1;
	if(member=="Chunjung")					return 2;
	if(member=="Viola")						return 3;
	if(member=="�p��")						return 4;
	if(member=="���b��")					return 5;
	if(member=="����� Anita")				return 6;
	if(member=="Ray")						return 7;
	if(member=="Max Weng")					return 8;
	if(member=="�K (Christine)")			return 9;
	if(member=="������")					return 10;
	if(member=="Wan-Cih")					return 11;
	if(member=="Amine")						return 12;
	if(member=="ChiaoYa")					return 13;
	if(member=="����")						return 14;
	if(member=="Sophia Li")					return 15;
	if(member=="Sara")						return 16;
	if(member=="Eddie")						return 17;
	if(member=="�L�®f Austin")				return 18;
	if(member=="Joyce")						return 19;
	if(member=="michelle")					return 20;
	if(member=="Lily")						return 21;
	if(member=="���{�g")					return 22;
	if(member=="Katie")						return 23;
	if(member=="�����N")					return 24;
	if(member=="Sophia Yang")				return 25;
	if(member=="Grace Lu")					return 26;
	if(member=="Jane")						return 27;
	if(member=="Avery")						return 28;
	if(member=="Mia")						return 29;
	return 9999;
}