//Mihajlo Pachovski INKI985
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct tempGradovi {
    string grad;
    int tempDenski;
    int tempNokjni;
    void print() {
        cout << grad << " - Den: " << tempDenski << ", Nokj: " << tempNokjni << endl;}};
bool sortFunction(tempGradovi a, tempGradovi b) {
    if (a.tempDenski < b.tempDenski)
        return true;
    else if (a.tempDenski == b.tempDenski)
        return a.tempNokjni < b.tempNokjni;
    else
        return false;}
void createFile(vector<tempGradovi> gradovi) {
    ofstream file("INKI985_TEMPERATURI.txt");
    for (auto it = gradovi.begin(); it != gradovi.end(); it++) {
        file << it->grad << " - Denska: " << it->tempDenski << ", Nokjna: " << it->tempNokjni << endl;}
    file.close();}
int main() {
    vector<tempGradovi> gradovi = {
        {"Bitola", 13, 9},
        {"Prilep", 13, 8},
        {"Ohrid", 14, 10},
        {"Struga", 14, 10},
        {"Debar", 16, 9},
        {"Tetovo", 14, 10},
        {"Gostivar", 14, 10},
        {"Kumanovo", 17, 10},
        {"Veles", 17, 11},
        {"Negotino", 16, 11}};
    sort(gradovi.begin(), gradovi.end(), sortFunction);
    for (auto it = gradovi.begin(); it != gradovi.end(); it++) {
        it->print();}
    createFile(gradovi);
    return 0;}