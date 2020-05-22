#pragma once
#include"Data.h"

void DataCin(Request* (&d), int& n);
void DataReadFromFile(Request* (&d), int& n, string namefile);
void Print(Request * d, int n);
void DataChange(Request* d, int n);
void Copy(Request *d_n, Request *d_o, int n);
void AddData(Request* (&d), int& n);
void DeleteData(Request* (&d), int& n);
void SortingData(Request* d, int& n);
void SaveData(Request* d, int& n, string namefile);
void SumRequest(Request* &d, int &n, string namefile);
