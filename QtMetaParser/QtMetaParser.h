#pragma once
#include "Common.h"
#include <pro.h>
#include <vector>

//ÿ���������˽��d����

struct QMetaObject_d 
{
	ea_t superdata;
	ea_t stringdata;
	ea_t data;
	ea_t static_metacall;
	ea_t relatedMetaObjects;
	//reserved for future use
	ea_t extradata;
};

struct QtMetaData 
{
	unsigned int revision;
	unsigned int classname;
	unsigned int classinfoCount, classinfoData;
	unsigned int methodCount, methodData;
	unsigned int propertyCount, propertyData;
	unsigned int enumeratorCount, enumeratorData;
	unsigned int constructorCount, constructorData;
	unsigned int signalCount;
};

struct QMethodData
{
	//��������
	std::string methodName;
	//����ֵ����
	std::string retType;
	//��������
	int argCount;
	//��������ƫ��
	std::uint32_t paramOffset;
	//��������
	std::vector<std::string> paramsType;
	//������
	std::vector<std::string> paramsName;
};

class QtMetaParser
{
public:
	QtMetaParser();
	~QtMetaParser();
public:
	void StartParse();
private:
	bool parseStringData(ea_t addr);
	bool parseMetaData(ea_t addr);
	std::string getParamType(std::uint32_t paramIndex);
private:
	std::vector<std::string> stringDataList;
	std::vector<QMethodData> signalMethodList;
	std::vector<QMethodData> slotMethodList;
};