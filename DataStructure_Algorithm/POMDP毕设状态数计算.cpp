#include<iostream>
#include<stdio.h>

#define acs 2
#define velocity_0 2
#define con 0
#define DTC_max 4

using namespace std;

static char sign[201][201][201][201];//人、自 的联合状态：DTC_human、v_human、DTC_host、v_host
static int count_state = 0;
void state_trans(int DTC_human, int v_human, int DTC_host, int v_host,int a_human,int a_host) {
	
	//联合状态更新
	int v2 = v_human + a_human;

	if (a_human != 0) {
		int s = (v2*v2 - v_human*v_human) / (2 * a_human);
		DTC_human += s;
	}
	else {
		DTC_human += v_human;
	}
	v_human = v2;

	v2 = v_host + a_host;

	if (a_host != 0) {
		int s = (v2*v2 - v_host*v_host) / (2 * a_host);
		DTC_host += s;
	}
	else {
		DTC_host += v_host;
	}

	v_host = v2;

	//标记已经到达过的状态
	if (sign[DTC_human][v_human][DTC_host][v_host] == '@')return;
	sign[DTC_human][v_human][DTC_host][v_host] = '@';
	count_state++;
	printf("state%d: %d,%d,%d,%d\n", count_state, DTC_human, v_human, DTC_host, v_host);
	

	//继续深搜
	if (DTC_host < DTC_max) {
		if (DTC_human >= DTC_max) {
			state_trans(DTC_human, v_human, DTC_host, v_host, acs, acs);
			state_trans(DTC_human, v_human, DTC_host, v_host, con, acs);
			//state_trans(DTC_human, v_human, DTC_host, v_host, dec, acs);
		}
		else
		{
			state_trans(DTC_human, v_human, DTC_host, v_host, acs, acs);
			state_trans(DTC_human, v_human, DTC_host, v_host, acs, con);
			//state_trans(DTC_human, v_human, DTC_host, v_host, acs, dec);
			state_trans(DTC_human, v_human, DTC_host, v_host, con, acs);
			state_trans(DTC_human, v_human, DTC_host, v_host, con, con);
			//state_trans(DTC_human, v_human, DTC_host, v_host, con, dec);
		/*	state_trans(DTC_human, v_human, DTC_host, v_host, dec, acs);
			state_trans(DTC_human, v_human, DTC_host, v_host, dec, con);
			state_trans(DTC_human, v_human, DTC_host, v_host, dec, dec);*/
		}
	}
}
int main() {

	memset(sign, '0', sizeof(sign));
	sign[0][velocity_0][0][velocity_0] = '@';

	state_trans(0, velocity_0, 0, velocity_0, acs, acs);
	state_trans(0, velocity_0, 0, velocity_0, acs, con);
	//state_trans(108, 0, 82, 0, acs, dec);
	state_trans(0, velocity_0, 0, velocity_0, con, acs);
	state_trans(0, velocity_0, 0, velocity_0, con, con);
	//state_trans(108, 0, 82, 0, con, dec);
	//state_trans(108, 0, 82, 0, dec, acs);
	//state_trans(108, 0, 82, 0, dec, con);
	//state_trans(108, 0, 82, 0, dec, dec);

	printf("%d\n", count_state);
	system("pause");
	return 0;
}