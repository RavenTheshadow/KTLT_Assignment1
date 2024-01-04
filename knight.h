#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
void docevent13();
void xulixau(string s);
void doc(string file_input,int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown);
bool isprime(int n0);
int fibonanci(int n0);
void mountain13(int &mtx,int &mti);
int event1to5(int HP,int &phoenixdown,float baseDamage,int &level,int i);
int event6(int HP,int &remedy,int &level,int i,int &small);
int event7(int &maidenkiss,int level,int i,int &frog);
int event11(int HP,int level,int phoenixdown);
int event12(int HP);
int event15(int remedy);
int event16(int maidenkiss);
int event17(int phoenixdown);
void event19(string fileName,int &phoenixdown,int &remedy,int &maidenkiss);
int event18(string fileName,int HP);
int event13(int j,int HP);
#endif // __KNIGHT_H__
