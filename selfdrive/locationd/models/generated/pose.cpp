#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7100903012294603026) {
   out_7100903012294603026[0] = delta_x[0] + nom_x[0];
   out_7100903012294603026[1] = delta_x[1] + nom_x[1];
   out_7100903012294603026[2] = delta_x[2] + nom_x[2];
   out_7100903012294603026[3] = delta_x[3] + nom_x[3];
   out_7100903012294603026[4] = delta_x[4] + nom_x[4];
   out_7100903012294603026[5] = delta_x[5] + nom_x[5];
   out_7100903012294603026[6] = delta_x[6] + nom_x[6];
   out_7100903012294603026[7] = delta_x[7] + nom_x[7];
   out_7100903012294603026[8] = delta_x[8] + nom_x[8];
   out_7100903012294603026[9] = delta_x[9] + nom_x[9];
   out_7100903012294603026[10] = delta_x[10] + nom_x[10];
   out_7100903012294603026[11] = delta_x[11] + nom_x[11];
   out_7100903012294603026[12] = delta_x[12] + nom_x[12];
   out_7100903012294603026[13] = delta_x[13] + nom_x[13];
   out_7100903012294603026[14] = delta_x[14] + nom_x[14];
   out_7100903012294603026[15] = delta_x[15] + nom_x[15];
   out_7100903012294603026[16] = delta_x[16] + nom_x[16];
   out_7100903012294603026[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2844686309860313113) {
   out_2844686309860313113[0] = -nom_x[0] + true_x[0];
   out_2844686309860313113[1] = -nom_x[1] + true_x[1];
   out_2844686309860313113[2] = -nom_x[2] + true_x[2];
   out_2844686309860313113[3] = -nom_x[3] + true_x[3];
   out_2844686309860313113[4] = -nom_x[4] + true_x[4];
   out_2844686309860313113[5] = -nom_x[5] + true_x[5];
   out_2844686309860313113[6] = -nom_x[6] + true_x[6];
   out_2844686309860313113[7] = -nom_x[7] + true_x[7];
   out_2844686309860313113[8] = -nom_x[8] + true_x[8];
   out_2844686309860313113[9] = -nom_x[9] + true_x[9];
   out_2844686309860313113[10] = -nom_x[10] + true_x[10];
   out_2844686309860313113[11] = -nom_x[11] + true_x[11];
   out_2844686309860313113[12] = -nom_x[12] + true_x[12];
   out_2844686309860313113[13] = -nom_x[13] + true_x[13];
   out_2844686309860313113[14] = -nom_x[14] + true_x[14];
   out_2844686309860313113[15] = -nom_x[15] + true_x[15];
   out_2844686309860313113[16] = -nom_x[16] + true_x[16];
   out_2844686309860313113[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4111323928338927612) {
   out_4111323928338927612[0] = 1.0;
   out_4111323928338927612[1] = 0.0;
   out_4111323928338927612[2] = 0.0;
   out_4111323928338927612[3] = 0.0;
   out_4111323928338927612[4] = 0.0;
   out_4111323928338927612[5] = 0.0;
   out_4111323928338927612[6] = 0.0;
   out_4111323928338927612[7] = 0.0;
   out_4111323928338927612[8] = 0.0;
   out_4111323928338927612[9] = 0.0;
   out_4111323928338927612[10] = 0.0;
   out_4111323928338927612[11] = 0.0;
   out_4111323928338927612[12] = 0.0;
   out_4111323928338927612[13] = 0.0;
   out_4111323928338927612[14] = 0.0;
   out_4111323928338927612[15] = 0.0;
   out_4111323928338927612[16] = 0.0;
   out_4111323928338927612[17] = 0.0;
   out_4111323928338927612[18] = 0.0;
   out_4111323928338927612[19] = 1.0;
   out_4111323928338927612[20] = 0.0;
   out_4111323928338927612[21] = 0.0;
   out_4111323928338927612[22] = 0.0;
   out_4111323928338927612[23] = 0.0;
   out_4111323928338927612[24] = 0.0;
   out_4111323928338927612[25] = 0.0;
   out_4111323928338927612[26] = 0.0;
   out_4111323928338927612[27] = 0.0;
   out_4111323928338927612[28] = 0.0;
   out_4111323928338927612[29] = 0.0;
   out_4111323928338927612[30] = 0.0;
   out_4111323928338927612[31] = 0.0;
   out_4111323928338927612[32] = 0.0;
   out_4111323928338927612[33] = 0.0;
   out_4111323928338927612[34] = 0.0;
   out_4111323928338927612[35] = 0.0;
   out_4111323928338927612[36] = 0.0;
   out_4111323928338927612[37] = 0.0;
   out_4111323928338927612[38] = 1.0;
   out_4111323928338927612[39] = 0.0;
   out_4111323928338927612[40] = 0.0;
   out_4111323928338927612[41] = 0.0;
   out_4111323928338927612[42] = 0.0;
   out_4111323928338927612[43] = 0.0;
   out_4111323928338927612[44] = 0.0;
   out_4111323928338927612[45] = 0.0;
   out_4111323928338927612[46] = 0.0;
   out_4111323928338927612[47] = 0.0;
   out_4111323928338927612[48] = 0.0;
   out_4111323928338927612[49] = 0.0;
   out_4111323928338927612[50] = 0.0;
   out_4111323928338927612[51] = 0.0;
   out_4111323928338927612[52] = 0.0;
   out_4111323928338927612[53] = 0.0;
   out_4111323928338927612[54] = 0.0;
   out_4111323928338927612[55] = 0.0;
   out_4111323928338927612[56] = 0.0;
   out_4111323928338927612[57] = 1.0;
   out_4111323928338927612[58] = 0.0;
   out_4111323928338927612[59] = 0.0;
   out_4111323928338927612[60] = 0.0;
   out_4111323928338927612[61] = 0.0;
   out_4111323928338927612[62] = 0.0;
   out_4111323928338927612[63] = 0.0;
   out_4111323928338927612[64] = 0.0;
   out_4111323928338927612[65] = 0.0;
   out_4111323928338927612[66] = 0.0;
   out_4111323928338927612[67] = 0.0;
   out_4111323928338927612[68] = 0.0;
   out_4111323928338927612[69] = 0.0;
   out_4111323928338927612[70] = 0.0;
   out_4111323928338927612[71] = 0.0;
   out_4111323928338927612[72] = 0.0;
   out_4111323928338927612[73] = 0.0;
   out_4111323928338927612[74] = 0.0;
   out_4111323928338927612[75] = 0.0;
   out_4111323928338927612[76] = 1.0;
   out_4111323928338927612[77] = 0.0;
   out_4111323928338927612[78] = 0.0;
   out_4111323928338927612[79] = 0.0;
   out_4111323928338927612[80] = 0.0;
   out_4111323928338927612[81] = 0.0;
   out_4111323928338927612[82] = 0.0;
   out_4111323928338927612[83] = 0.0;
   out_4111323928338927612[84] = 0.0;
   out_4111323928338927612[85] = 0.0;
   out_4111323928338927612[86] = 0.0;
   out_4111323928338927612[87] = 0.0;
   out_4111323928338927612[88] = 0.0;
   out_4111323928338927612[89] = 0.0;
   out_4111323928338927612[90] = 0.0;
   out_4111323928338927612[91] = 0.0;
   out_4111323928338927612[92] = 0.0;
   out_4111323928338927612[93] = 0.0;
   out_4111323928338927612[94] = 0.0;
   out_4111323928338927612[95] = 1.0;
   out_4111323928338927612[96] = 0.0;
   out_4111323928338927612[97] = 0.0;
   out_4111323928338927612[98] = 0.0;
   out_4111323928338927612[99] = 0.0;
   out_4111323928338927612[100] = 0.0;
   out_4111323928338927612[101] = 0.0;
   out_4111323928338927612[102] = 0.0;
   out_4111323928338927612[103] = 0.0;
   out_4111323928338927612[104] = 0.0;
   out_4111323928338927612[105] = 0.0;
   out_4111323928338927612[106] = 0.0;
   out_4111323928338927612[107] = 0.0;
   out_4111323928338927612[108] = 0.0;
   out_4111323928338927612[109] = 0.0;
   out_4111323928338927612[110] = 0.0;
   out_4111323928338927612[111] = 0.0;
   out_4111323928338927612[112] = 0.0;
   out_4111323928338927612[113] = 0.0;
   out_4111323928338927612[114] = 1.0;
   out_4111323928338927612[115] = 0.0;
   out_4111323928338927612[116] = 0.0;
   out_4111323928338927612[117] = 0.0;
   out_4111323928338927612[118] = 0.0;
   out_4111323928338927612[119] = 0.0;
   out_4111323928338927612[120] = 0.0;
   out_4111323928338927612[121] = 0.0;
   out_4111323928338927612[122] = 0.0;
   out_4111323928338927612[123] = 0.0;
   out_4111323928338927612[124] = 0.0;
   out_4111323928338927612[125] = 0.0;
   out_4111323928338927612[126] = 0.0;
   out_4111323928338927612[127] = 0.0;
   out_4111323928338927612[128] = 0.0;
   out_4111323928338927612[129] = 0.0;
   out_4111323928338927612[130] = 0.0;
   out_4111323928338927612[131] = 0.0;
   out_4111323928338927612[132] = 0.0;
   out_4111323928338927612[133] = 1.0;
   out_4111323928338927612[134] = 0.0;
   out_4111323928338927612[135] = 0.0;
   out_4111323928338927612[136] = 0.0;
   out_4111323928338927612[137] = 0.0;
   out_4111323928338927612[138] = 0.0;
   out_4111323928338927612[139] = 0.0;
   out_4111323928338927612[140] = 0.0;
   out_4111323928338927612[141] = 0.0;
   out_4111323928338927612[142] = 0.0;
   out_4111323928338927612[143] = 0.0;
   out_4111323928338927612[144] = 0.0;
   out_4111323928338927612[145] = 0.0;
   out_4111323928338927612[146] = 0.0;
   out_4111323928338927612[147] = 0.0;
   out_4111323928338927612[148] = 0.0;
   out_4111323928338927612[149] = 0.0;
   out_4111323928338927612[150] = 0.0;
   out_4111323928338927612[151] = 0.0;
   out_4111323928338927612[152] = 1.0;
   out_4111323928338927612[153] = 0.0;
   out_4111323928338927612[154] = 0.0;
   out_4111323928338927612[155] = 0.0;
   out_4111323928338927612[156] = 0.0;
   out_4111323928338927612[157] = 0.0;
   out_4111323928338927612[158] = 0.0;
   out_4111323928338927612[159] = 0.0;
   out_4111323928338927612[160] = 0.0;
   out_4111323928338927612[161] = 0.0;
   out_4111323928338927612[162] = 0.0;
   out_4111323928338927612[163] = 0.0;
   out_4111323928338927612[164] = 0.0;
   out_4111323928338927612[165] = 0.0;
   out_4111323928338927612[166] = 0.0;
   out_4111323928338927612[167] = 0.0;
   out_4111323928338927612[168] = 0.0;
   out_4111323928338927612[169] = 0.0;
   out_4111323928338927612[170] = 0.0;
   out_4111323928338927612[171] = 1.0;
   out_4111323928338927612[172] = 0.0;
   out_4111323928338927612[173] = 0.0;
   out_4111323928338927612[174] = 0.0;
   out_4111323928338927612[175] = 0.0;
   out_4111323928338927612[176] = 0.0;
   out_4111323928338927612[177] = 0.0;
   out_4111323928338927612[178] = 0.0;
   out_4111323928338927612[179] = 0.0;
   out_4111323928338927612[180] = 0.0;
   out_4111323928338927612[181] = 0.0;
   out_4111323928338927612[182] = 0.0;
   out_4111323928338927612[183] = 0.0;
   out_4111323928338927612[184] = 0.0;
   out_4111323928338927612[185] = 0.0;
   out_4111323928338927612[186] = 0.0;
   out_4111323928338927612[187] = 0.0;
   out_4111323928338927612[188] = 0.0;
   out_4111323928338927612[189] = 0.0;
   out_4111323928338927612[190] = 1.0;
   out_4111323928338927612[191] = 0.0;
   out_4111323928338927612[192] = 0.0;
   out_4111323928338927612[193] = 0.0;
   out_4111323928338927612[194] = 0.0;
   out_4111323928338927612[195] = 0.0;
   out_4111323928338927612[196] = 0.0;
   out_4111323928338927612[197] = 0.0;
   out_4111323928338927612[198] = 0.0;
   out_4111323928338927612[199] = 0.0;
   out_4111323928338927612[200] = 0.0;
   out_4111323928338927612[201] = 0.0;
   out_4111323928338927612[202] = 0.0;
   out_4111323928338927612[203] = 0.0;
   out_4111323928338927612[204] = 0.0;
   out_4111323928338927612[205] = 0.0;
   out_4111323928338927612[206] = 0.0;
   out_4111323928338927612[207] = 0.0;
   out_4111323928338927612[208] = 0.0;
   out_4111323928338927612[209] = 1.0;
   out_4111323928338927612[210] = 0.0;
   out_4111323928338927612[211] = 0.0;
   out_4111323928338927612[212] = 0.0;
   out_4111323928338927612[213] = 0.0;
   out_4111323928338927612[214] = 0.0;
   out_4111323928338927612[215] = 0.0;
   out_4111323928338927612[216] = 0.0;
   out_4111323928338927612[217] = 0.0;
   out_4111323928338927612[218] = 0.0;
   out_4111323928338927612[219] = 0.0;
   out_4111323928338927612[220] = 0.0;
   out_4111323928338927612[221] = 0.0;
   out_4111323928338927612[222] = 0.0;
   out_4111323928338927612[223] = 0.0;
   out_4111323928338927612[224] = 0.0;
   out_4111323928338927612[225] = 0.0;
   out_4111323928338927612[226] = 0.0;
   out_4111323928338927612[227] = 0.0;
   out_4111323928338927612[228] = 1.0;
   out_4111323928338927612[229] = 0.0;
   out_4111323928338927612[230] = 0.0;
   out_4111323928338927612[231] = 0.0;
   out_4111323928338927612[232] = 0.0;
   out_4111323928338927612[233] = 0.0;
   out_4111323928338927612[234] = 0.0;
   out_4111323928338927612[235] = 0.0;
   out_4111323928338927612[236] = 0.0;
   out_4111323928338927612[237] = 0.0;
   out_4111323928338927612[238] = 0.0;
   out_4111323928338927612[239] = 0.0;
   out_4111323928338927612[240] = 0.0;
   out_4111323928338927612[241] = 0.0;
   out_4111323928338927612[242] = 0.0;
   out_4111323928338927612[243] = 0.0;
   out_4111323928338927612[244] = 0.0;
   out_4111323928338927612[245] = 0.0;
   out_4111323928338927612[246] = 0.0;
   out_4111323928338927612[247] = 1.0;
   out_4111323928338927612[248] = 0.0;
   out_4111323928338927612[249] = 0.0;
   out_4111323928338927612[250] = 0.0;
   out_4111323928338927612[251] = 0.0;
   out_4111323928338927612[252] = 0.0;
   out_4111323928338927612[253] = 0.0;
   out_4111323928338927612[254] = 0.0;
   out_4111323928338927612[255] = 0.0;
   out_4111323928338927612[256] = 0.0;
   out_4111323928338927612[257] = 0.0;
   out_4111323928338927612[258] = 0.0;
   out_4111323928338927612[259] = 0.0;
   out_4111323928338927612[260] = 0.0;
   out_4111323928338927612[261] = 0.0;
   out_4111323928338927612[262] = 0.0;
   out_4111323928338927612[263] = 0.0;
   out_4111323928338927612[264] = 0.0;
   out_4111323928338927612[265] = 0.0;
   out_4111323928338927612[266] = 1.0;
   out_4111323928338927612[267] = 0.0;
   out_4111323928338927612[268] = 0.0;
   out_4111323928338927612[269] = 0.0;
   out_4111323928338927612[270] = 0.0;
   out_4111323928338927612[271] = 0.0;
   out_4111323928338927612[272] = 0.0;
   out_4111323928338927612[273] = 0.0;
   out_4111323928338927612[274] = 0.0;
   out_4111323928338927612[275] = 0.0;
   out_4111323928338927612[276] = 0.0;
   out_4111323928338927612[277] = 0.0;
   out_4111323928338927612[278] = 0.0;
   out_4111323928338927612[279] = 0.0;
   out_4111323928338927612[280] = 0.0;
   out_4111323928338927612[281] = 0.0;
   out_4111323928338927612[282] = 0.0;
   out_4111323928338927612[283] = 0.0;
   out_4111323928338927612[284] = 0.0;
   out_4111323928338927612[285] = 1.0;
   out_4111323928338927612[286] = 0.0;
   out_4111323928338927612[287] = 0.0;
   out_4111323928338927612[288] = 0.0;
   out_4111323928338927612[289] = 0.0;
   out_4111323928338927612[290] = 0.0;
   out_4111323928338927612[291] = 0.0;
   out_4111323928338927612[292] = 0.0;
   out_4111323928338927612[293] = 0.0;
   out_4111323928338927612[294] = 0.0;
   out_4111323928338927612[295] = 0.0;
   out_4111323928338927612[296] = 0.0;
   out_4111323928338927612[297] = 0.0;
   out_4111323928338927612[298] = 0.0;
   out_4111323928338927612[299] = 0.0;
   out_4111323928338927612[300] = 0.0;
   out_4111323928338927612[301] = 0.0;
   out_4111323928338927612[302] = 0.0;
   out_4111323928338927612[303] = 0.0;
   out_4111323928338927612[304] = 1.0;
   out_4111323928338927612[305] = 0.0;
   out_4111323928338927612[306] = 0.0;
   out_4111323928338927612[307] = 0.0;
   out_4111323928338927612[308] = 0.0;
   out_4111323928338927612[309] = 0.0;
   out_4111323928338927612[310] = 0.0;
   out_4111323928338927612[311] = 0.0;
   out_4111323928338927612[312] = 0.0;
   out_4111323928338927612[313] = 0.0;
   out_4111323928338927612[314] = 0.0;
   out_4111323928338927612[315] = 0.0;
   out_4111323928338927612[316] = 0.0;
   out_4111323928338927612[317] = 0.0;
   out_4111323928338927612[318] = 0.0;
   out_4111323928338927612[319] = 0.0;
   out_4111323928338927612[320] = 0.0;
   out_4111323928338927612[321] = 0.0;
   out_4111323928338927612[322] = 0.0;
   out_4111323928338927612[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_959899990977101830) {
   out_959899990977101830[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_959899990977101830[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_959899990977101830[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_959899990977101830[3] = dt*state[12] + state[3];
   out_959899990977101830[4] = dt*state[13] + state[4];
   out_959899990977101830[5] = dt*state[14] + state[5];
   out_959899990977101830[6] = state[6];
   out_959899990977101830[7] = state[7];
   out_959899990977101830[8] = state[8];
   out_959899990977101830[9] = state[9];
   out_959899990977101830[10] = state[10];
   out_959899990977101830[11] = state[11];
   out_959899990977101830[12] = state[12];
   out_959899990977101830[13] = state[13];
   out_959899990977101830[14] = state[14];
   out_959899990977101830[15] = state[15];
   out_959899990977101830[16] = state[16];
   out_959899990977101830[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7787940412229259226) {
   out_7787940412229259226[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7787940412229259226[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7787940412229259226[2] = 0;
   out_7787940412229259226[3] = 0;
   out_7787940412229259226[4] = 0;
   out_7787940412229259226[5] = 0;
   out_7787940412229259226[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7787940412229259226[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7787940412229259226[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7787940412229259226[9] = 0;
   out_7787940412229259226[10] = 0;
   out_7787940412229259226[11] = 0;
   out_7787940412229259226[12] = 0;
   out_7787940412229259226[13] = 0;
   out_7787940412229259226[14] = 0;
   out_7787940412229259226[15] = 0;
   out_7787940412229259226[16] = 0;
   out_7787940412229259226[17] = 0;
   out_7787940412229259226[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7787940412229259226[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7787940412229259226[20] = 0;
   out_7787940412229259226[21] = 0;
   out_7787940412229259226[22] = 0;
   out_7787940412229259226[23] = 0;
   out_7787940412229259226[24] = 0;
   out_7787940412229259226[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7787940412229259226[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7787940412229259226[27] = 0;
   out_7787940412229259226[28] = 0;
   out_7787940412229259226[29] = 0;
   out_7787940412229259226[30] = 0;
   out_7787940412229259226[31] = 0;
   out_7787940412229259226[32] = 0;
   out_7787940412229259226[33] = 0;
   out_7787940412229259226[34] = 0;
   out_7787940412229259226[35] = 0;
   out_7787940412229259226[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7787940412229259226[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7787940412229259226[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7787940412229259226[39] = 0;
   out_7787940412229259226[40] = 0;
   out_7787940412229259226[41] = 0;
   out_7787940412229259226[42] = 0;
   out_7787940412229259226[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7787940412229259226[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7787940412229259226[45] = 0;
   out_7787940412229259226[46] = 0;
   out_7787940412229259226[47] = 0;
   out_7787940412229259226[48] = 0;
   out_7787940412229259226[49] = 0;
   out_7787940412229259226[50] = 0;
   out_7787940412229259226[51] = 0;
   out_7787940412229259226[52] = 0;
   out_7787940412229259226[53] = 0;
   out_7787940412229259226[54] = 0;
   out_7787940412229259226[55] = 0;
   out_7787940412229259226[56] = 0;
   out_7787940412229259226[57] = 1;
   out_7787940412229259226[58] = 0;
   out_7787940412229259226[59] = 0;
   out_7787940412229259226[60] = 0;
   out_7787940412229259226[61] = 0;
   out_7787940412229259226[62] = 0;
   out_7787940412229259226[63] = 0;
   out_7787940412229259226[64] = 0;
   out_7787940412229259226[65] = 0;
   out_7787940412229259226[66] = dt;
   out_7787940412229259226[67] = 0;
   out_7787940412229259226[68] = 0;
   out_7787940412229259226[69] = 0;
   out_7787940412229259226[70] = 0;
   out_7787940412229259226[71] = 0;
   out_7787940412229259226[72] = 0;
   out_7787940412229259226[73] = 0;
   out_7787940412229259226[74] = 0;
   out_7787940412229259226[75] = 0;
   out_7787940412229259226[76] = 1;
   out_7787940412229259226[77] = 0;
   out_7787940412229259226[78] = 0;
   out_7787940412229259226[79] = 0;
   out_7787940412229259226[80] = 0;
   out_7787940412229259226[81] = 0;
   out_7787940412229259226[82] = 0;
   out_7787940412229259226[83] = 0;
   out_7787940412229259226[84] = 0;
   out_7787940412229259226[85] = dt;
   out_7787940412229259226[86] = 0;
   out_7787940412229259226[87] = 0;
   out_7787940412229259226[88] = 0;
   out_7787940412229259226[89] = 0;
   out_7787940412229259226[90] = 0;
   out_7787940412229259226[91] = 0;
   out_7787940412229259226[92] = 0;
   out_7787940412229259226[93] = 0;
   out_7787940412229259226[94] = 0;
   out_7787940412229259226[95] = 1;
   out_7787940412229259226[96] = 0;
   out_7787940412229259226[97] = 0;
   out_7787940412229259226[98] = 0;
   out_7787940412229259226[99] = 0;
   out_7787940412229259226[100] = 0;
   out_7787940412229259226[101] = 0;
   out_7787940412229259226[102] = 0;
   out_7787940412229259226[103] = 0;
   out_7787940412229259226[104] = dt;
   out_7787940412229259226[105] = 0;
   out_7787940412229259226[106] = 0;
   out_7787940412229259226[107] = 0;
   out_7787940412229259226[108] = 0;
   out_7787940412229259226[109] = 0;
   out_7787940412229259226[110] = 0;
   out_7787940412229259226[111] = 0;
   out_7787940412229259226[112] = 0;
   out_7787940412229259226[113] = 0;
   out_7787940412229259226[114] = 1;
   out_7787940412229259226[115] = 0;
   out_7787940412229259226[116] = 0;
   out_7787940412229259226[117] = 0;
   out_7787940412229259226[118] = 0;
   out_7787940412229259226[119] = 0;
   out_7787940412229259226[120] = 0;
   out_7787940412229259226[121] = 0;
   out_7787940412229259226[122] = 0;
   out_7787940412229259226[123] = 0;
   out_7787940412229259226[124] = 0;
   out_7787940412229259226[125] = 0;
   out_7787940412229259226[126] = 0;
   out_7787940412229259226[127] = 0;
   out_7787940412229259226[128] = 0;
   out_7787940412229259226[129] = 0;
   out_7787940412229259226[130] = 0;
   out_7787940412229259226[131] = 0;
   out_7787940412229259226[132] = 0;
   out_7787940412229259226[133] = 1;
   out_7787940412229259226[134] = 0;
   out_7787940412229259226[135] = 0;
   out_7787940412229259226[136] = 0;
   out_7787940412229259226[137] = 0;
   out_7787940412229259226[138] = 0;
   out_7787940412229259226[139] = 0;
   out_7787940412229259226[140] = 0;
   out_7787940412229259226[141] = 0;
   out_7787940412229259226[142] = 0;
   out_7787940412229259226[143] = 0;
   out_7787940412229259226[144] = 0;
   out_7787940412229259226[145] = 0;
   out_7787940412229259226[146] = 0;
   out_7787940412229259226[147] = 0;
   out_7787940412229259226[148] = 0;
   out_7787940412229259226[149] = 0;
   out_7787940412229259226[150] = 0;
   out_7787940412229259226[151] = 0;
   out_7787940412229259226[152] = 1;
   out_7787940412229259226[153] = 0;
   out_7787940412229259226[154] = 0;
   out_7787940412229259226[155] = 0;
   out_7787940412229259226[156] = 0;
   out_7787940412229259226[157] = 0;
   out_7787940412229259226[158] = 0;
   out_7787940412229259226[159] = 0;
   out_7787940412229259226[160] = 0;
   out_7787940412229259226[161] = 0;
   out_7787940412229259226[162] = 0;
   out_7787940412229259226[163] = 0;
   out_7787940412229259226[164] = 0;
   out_7787940412229259226[165] = 0;
   out_7787940412229259226[166] = 0;
   out_7787940412229259226[167] = 0;
   out_7787940412229259226[168] = 0;
   out_7787940412229259226[169] = 0;
   out_7787940412229259226[170] = 0;
   out_7787940412229259226[171] = 1;
   out_7787940412229259226[172] = 0;
   out_7787940412229259226[173] = 0;
   out_7787940412229259226[174] = 0;
   out_7787940412229259226[175] = 0;
   out_7787940412229259226[176] = 0;
   out_7787940412229259226[177] = 0;
   out_7787940412229259226[178] = 0;
   out_7787940412229259226[179] = 0;
   out_7787940412229259226[180] = 0;
   out_7787940412229259226[181] = 0;
   out_7787940412229259226[182] = 0;
   out_7787940412229259226[183] = 0;
   out_7787940412229259226[184] = 0;
   out_7787940412229259226[185] = 0;
   out_7787940412229259226[186] = 0;
   out_7787940412229259226[187] = 0;
   out_7787940412229259226[188] = 0;
   out_7787940412229259226[189] = 0;
   out_7787940412229259226[190] = 1;
   out_7787940412229259226[191] = 0;
   out_7787940412229259226[192] = 0;
   out_7787940412229259226[193] = 0;
   out_7787940412229259226[194] = 0;
   out_7787940412229259226[195] = 0;
   out_7787940412229259226[196] = 0;
   out_7787940412229259226[197] = 0;
   out_7787940412229259226[198] = 0;
   out_7787940412229259226[199] = 0;
   out_7787940412229259226[200] = 0;
   out_7787940412229259226[201] = 0;
   out_7787940412229259226[202] = 0;
   out_7787940412229259226[203] = 0;
   out_7787940412229259226[204] = 0;
   out_7787940412229259226[205] = 0;
   out_7787940412229259226[206] = 0;
   out_7787940412229259226[207] = 0;
   out_7787940412229259226[208] = 0;
   out_7787940412229259226[209] = 1;
   out_7787940412229259226[210] = 0;
   out_7787940412229259226[211] = 0;
   out_7787940412229259226[212] = 0;
   out_7787940412229259226[213] = 0;
   out_7787940412229259226[214] = 0;
   out_7787940412229259226[215] = 0;
   out_7787940412229259226[216] = 0;
   out_7787940412229259226[217] = 0;
   out_7787940412229259226[218] = 0;
   out_7787940412229259226[219] = 0;
   out_7787940412229259226[220] = 0;
   out_7787940412229259226[221] = 0;
   out_7787940412229259226[222] = 0;
   out_7787940412229259226[223] = 0;
   out_7787940412229259226[224] = 0;
   out_7787940412229259226[225] = 0;
   out_7787940412229259226[226] = 0;
   out_7787940412229259226[227] = 0;
   out_7787940412229259226[228] = 1;
   out_7787940412229259226[229] = 0;
   out_7787940412229259226[230] = 0;
   out_7787940412229259226[231] = 0;
   out_7787940412229259226[232] = 0;
   out_7787940412229259226[233] = 0;
   out_7787940412229259226[234] = 0;
   out_7787940412229259226[235] = 0;
   out_7787940412229259226[236] = 0;
   out_7787940412229259226[237] = 0;
   out_7787940412229259226[238] = 0;
   out_7787940412229259226[239] = 0;
   out_7787940412229259226[240] = 0;
   out_7787940412229259226[241] = 0;
   out_7787940412229259226[242] = 0;
   out_7787940412229259226[243] = 0;
   out_7787940412229259226[244] = 0;
   out_7787940412229259226[245] = 0;
   out_7787940412229259226[246] = 0;
   out_7787940412229259226[247] = 1;
   out_7787940412229259226[248] = 0;
   out_7787940412229259226[249] = 0;
   out_7787940412229259226[250] = 0;
   out_7787940412229259226[251] = 0;
   out_7787940412229259226[252] = 0;
   out_7787940412229259226[253] = 0;
   out_7787940412229259226[254] = 0;
   out_7787940412229259226[255] = 0;
   out_7787940412229259226[256] = 0;
   out_7787940412229259226[257] = 0;
   out_7787940412229259226[258] = 0;
   out_7787940412229259226[259] = 0;
   out_7787940412229259226[260] = 0;
   out_7787940412229259226[261] = 0;
   out_7787940412229259226[262] = 0;
   out_7787940412229259226[263] = 0;
   out_7787940412229259226[264] = 0;
   out_7787940412229259226[265] = 0;
   out_7787940412229259226[266] = 1;
   out_7787940412229259226[267] = 0;
   out_7787940412229259226[268] = 0;
   out_7787940412229259226[269] = 0;
   out_7787940412229259226[270] = 0;
   out_7787940412229259226[271] = 0;
   out_7787940412229259226[272] = 0;
   out_7787940412229259226[273] = 0;
   out_7787940412229259226[274] = 0;
   out_7787940412229259226[275] = 0;
   out_7787940412229259226[276] = 0;
   out_7787940412229259226[277] = 0;
   out_7787940412229259226[278] = 0;
   out_7787940412229259226[279] = 0;
   out_7787940412229259226[280] = 0;
   out_7787940412229259226[281] = 0;
   out_7787940412229259226[282] = 0;
   out_7787940412229259226[283] = 0;
   out_7787940412229259226[284] = 0;
   out_7787940412229259226[285] = 1;
   out_7787940412229259226[286] = 0;
   out_7787940412229259226[287] = 0;
   out_7787940412229259226[288] = 0;
   out_7787940412229259226[289] = 0;
   out_7787940412229259226[290] = 0;
   out_7787940412229259226[291] = 0;
   out_7787940412229259226[292] = 0;
   out_7787940412229259226[293] = 0;
   out_7787940412229259226[294] = 0;
   out_7787940412229259226[295] = 0;
   out_7787940412229259226[296] = 0;
   out_7787940412229259226[297] = 0;
   out_7787940412229259226[298] = 0;
   out_7787940412229259226[299] = 0;
   out_7787940412229259226[300] = 0;
   out_7787940412229259226[301] = 0;
   out_7787940412229259226[302] = 0;
   out_7787940412229259226[303] = 0;
   out_7787940412229259226[304] = 1;
   out_7787940412229259226[305] = 0;
   out_7787940412229259226[306] = 0;
   out_7787940412229259226[307] = 0;
   out_7787940412229259226[308] = 0;
   out_7787940412229259226[309] = 0;
   out_7787940412229259226[310] = 0;
   out_7787940412229259226[311] = 0;
   out_7787940412229259226[312] = 0;
   out_7787940412229259226[313] = 0;
   out_7787940412229259226[314] = 0;
   out_7787940412229259226[315] = 0;
   out_7787940412229259226[316] = 0;
   out_7787940412229259226[317] = 0;
   out_7787940412229259226[318] = 0;
   out_7787940412229259226[319] = 0;
   out_7787940412229259226[320] = 0;
   out_7787940412229259226[321] = 0;
   out_7787940412229259226[322] = 0;
   out_7787940412229259226[323] = 1;
}
void h_4(double *state, double *unused, double *out_6652092636062505135) {
   out_6652092636062505135[0] = state[6] + state[9];
   out_6652092636062505135[1] = state[7] + state[10];
   out_6652092636062505135[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_5309271410221825716) {
   out_5309271410221825716[0] = 0;
   out_5309271410221825716[1] = 0;
   out_5309271410221825716[2] = 0;
   out_5309271410221825716[3] = 0;
   out_5309271410221825716[4] = 0;
   out_5309271410221825716[5] = 0;
   out_5309271410221825716[6] = 1;
   out_5309271410221825716[7] = 0;
   out_5309271410221825716[8] = 0;
   out_5309271410221825716[9] = 1;
   out_5309271410221825716[10] = 0;
   out_5309271410221825716[11] = 0;
   out_5309271410221825716[12] = 0;
   out_5309271410221825716[13] = 0;
   out_5309271410221825716[14] = 0;
   out_5309271410221825716[15] = 0;
   out_5309271410221825716[16] = 0;
   out_5309271410221825716[17] = 0;
   out_5309271410221825716[18] = 0;
   out_5309271410221825716[19] = 0;
   out_5309271410221825716[20] = 0;
   out_5309271410221825716[21] = 0;
   out_5309271410221825716[22] = 0;
   out_5309271410221825716[23] = 0;
   out_5309271410221825716[24] = 0;
   out_5309271410221825716[25] = 1;
   out_5309271410221825716[26] = 0;
   out_5309271410221825716[27] = 0;
   out_5309271410221825716[28] = 1;
   out_5309271410221825716[29] = 0;
   out_5309271410221825716[30] = 0;
   out_5309271410221825716[31] = 0;
   out_5309271410221825716[32] = 0;
   out_5309271410221825716[33] = 0;
   out_5309271410221825716[34] = 0;
   out_5309271410221825716[35] = 0;
   out_5309271410221825716[36] = 0;
   out_5309271410221825716[37] = 0;
   out_5309271410221825716[38] = 0;
   out_5309271410221825716[39] = 0;
   out_5309271410221825716[40] = 0;
   out_5309271410221825716[41] = 0;
   out_5309271410221825716[42] = 0;
   out_5309271410221825716[43] = 0;
   out_5309271410221825716[44] = 1;
   out_5309271410221825716[45] = 0;
   out_5309271410221825716[46] = 0;
   out_5309271410221825716[47] = 1;
   out_5309271410221825716[48] = 0;
   out_5309271410221825716[49] = 0;
   out_5309271410221825716[50] = 0;
   out_5309271410221825716[51] = 0;
   out_5309271410221825716[52] = 0;
   out_5309271410221825716[53] = 0;
}
void h_10(double *state, double *unused, double *out_7011707270713003130) {
   out_7011707270713003130[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7011707270713003130[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7011707270713003130[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8349416150201841682) {
   out_8349416150201841682[0] = 0;
   out_8349416150201841682[1] = 9.8100000000000005*cos(state[1]);
   out_8349416150201841682[2] = 0;
   out_8349416150201841682[3] = 0;
   out_8349416150201841682[4] = -state[8];
   out_8349416150201841682[5] = state[7];
   out_8349416150201841682[6] = 0;
   out_8349416150201841682[7] = state[5];
   out_8349416150201841682[8] = -state[4];
   out_8349416150201841682[9] = 0;
   out_8349416150201841682[10] = 0;
   out_8349416150201841682[11] = 0;
   out_8349416150201841682[12] = 1;
   out_8349416150201841682[13] = 0;
   out_8349416150201841682[14] = 0;
   out_8349416150201841682[15] = 1;
   out_8349416150201841682[16] = 0;
   out_8349416150201841682[17] = 0;
   out_8349416150201841682[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8349416150201841682[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8349416150201841682[20] = 0;
   out_8349416150201841682[21] = state[8];
   out_8349416150201841682[22] = 0;
   out_8349416150201841682[23] = -state[6];
   out_8349416150201841682[24] = -state[5];
   out_8349416150201841682[25] = 0;
   out_8349416150201841682[26] = state[3];
   out_8349416150201841682[27] = 0;
   out_8349416150201841682[28] = 0;
   out_8349416150201841682[29] = 0;
   out_8349416150201841682[30] = 0;
   out_8349416150201841682[31] = 1;
   out_8349416150201841682[32] = 0;
   out_8349416150201841682[33] = 0;
   out_8349416150201841682[34] = 1;
   out_8349416150201841682[35] = 0;
   out_8349416150201841682[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8349416150201841682[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8349416150201841682[38] = 0;
   out_8349416150201841682[39] = -state[7];
   out_8349416150201841682[40] = state[6];
   out_8349416150201841682[41] = 0;
   out_8349416150201841682[42] = state[4];
   out_8349416150201841682[43] = -state[3];
   out_8349416150201841682[44] = 0;
   out_8349416150201841682[45] = 0;
   out_8349416150201841682[46] = 0;
   out_8349416150201841682[47] = 0;
   out_8349416150201841682[48] = 0;
   out_8349416150201841682[49] = 0;
   out_8349416150201841682[50] = 1;
   out_8349416150201841682[51] = 0;
   out_8349416150201841682[52] = 0;
   out_8349416150201841682[53] = 1;
}
void h_13(double *state, double *unused, double *out_4264517865542995363) {
   out_4264517865542995363[0] = state[3];
   out_4264517865542995363[1] = state[4];
   out_4264517865542995363[2] = state[5];
}
void H_13(double *state, double *unused, double *out_8521545235554158517) {
   out_8521545235554158517[0] = 0;
   out_8521545235554158517[1] = 0;
   out_8521545235554158517[2] = 0;
   out_8521545235554158517[3] = 1;
   out_8521545235554158517[4] = 0;
   out_8521545235554158517[5] = 0;
   out_8521545235554158517[6] = 0;
   out_8521545235554158517[7] = 0;
   out_8521545235554158517[8] = 0;
   out_8521545235554158517[9] = 0;
   out_8521545235554158517[10] = 0;
   out_8521545235554158517[11] = 0;
   out_8521545235554158517[12] = 0;
   out_8521545235554158517[13] = 0;
   out_8521545235554158517[14] = 0;
   out_8521545235554158517[15] = 0;
   out_8521545235554158517[16] = 0;
   out_8521545235554158517[17] = 0;
   out_8521545235554158517[18] = 0;
   out_8521545235554158517[19] = 0;
   out_8521545235554158517[20] = 0;
   out_8521545235554158517[21] = 0;
   out_8521545235554158517[22] = 1;
   out_8521545235554158517[23] = 0;
   out_8521545235554158517[24] = 0;
   out_8521545235554158517[25] = 0;
   out_8521545235554158517[26] = 0;
   out_8521545235554158517[27] = 0;
   out_8521545235554158517[28] = 0;
   out_8521545235554158517[29] = 0;
   out_8521545235554158517[30] = 0;
   out_8521545235554158517[31] = 0;
   out_8521545235554158517[32] = 0;
   out_8521545235554158517[33] = 0;
   out_8521545235554158517[34] = 0;
   out_8521545235554158517[35] = 0;
   out_8521545235554158517[36] = 0;
   out_8521545235554158517[37] = 0;
   out_8521545235554158517[38] = 0;
   out_8521545235554158517[39] = 0;
   out_8521545235554158517[40] = 0;
   out_8521545235554158517[41] = 1;
   out_8521545235554158517[42] = 0;
   out_8521545235554158517[43] = 0;
   out_8521545235554158517[44] = 0;
   out_8521545235554158517[45] = 0;
   out_8521545235554158517[46] = 0;
   out_8521545235554158517[47] = 0;
   out_8521545235554158517[48] = 0;
   out_8521545235554158517[49] = 0;
   out_8521545235554158517[50] = 0;
   out_8521545235554158517[51] = 0;
   out_8521545235554158517[52] = 0;
   out_8521545235554158517[53] = 0;
}
void h_14(double *state, double *unused, double *out_3869257689260825595) {
   out_3869257689260825595[0] = state[6];
   out_3869257689260825595[1] = state[7];
   out_3869257689260825595[2] = state[8];
}
void H_14(double *state, double *unused, double *out_9174231807148241371) {
   out_9174231807148241371[0] = 0;
   out_9174231807148241371[1] = 0;
   out_9174231807148241371[2] = 0;
   out_9174231807148241371[3] = 0;
   out_9174231807148241371[4] = 0;
   out_9174231807148241371[5] = 0;
   out_9174231807148241371[6] = 1;
   out_9174231807148241371[7] = 0;
   out_9174231807148241371[8] = 0;
   out_9174231807148241371[9] = 0;
   out_9174231807148241371[10] = 0;
   out_9174231807148241371[11] = 0;
   out_9174231807148241371[12] = 0;
   out_9174231807148241371[13] = 0;
   out_9174231807148241371[14] = 0;
   out_9174231807148241371[15] = 0;
   out_9174231807148241371[16] = 0;
   out_9174231807148241371[17] = 0;
   out_9174231807148241371[18] = 0;
   out_9174231807148241371[19] = 0;
   out_9174231807148241371[20] = 0;
   out_9174231807148241371[21] = 0;
   out_9174231807148241371[22] = 0;
   out_9174231807148241371[23] = 0;
   out_9174231807148241371[24] = 0;
   out_9174231807148241371[25] = 1;
   out_9174231807148241371[26] = 0;
   out_9174231807148241371[27] = 0;
   out_9174231807148241371[28] = 0;
   out_9174231807148241371[29] = 0;
   out_9174231807148241371[30] = 0;
   out_9174231807148241371[31] = 0;
   out_9174231807148241371[32] = 0;
   out_9174231807148241371[33] = 0;
   out_9174231807148241371[34] = 0;
   out_9174231807148241371[35] = 0;
   out_9174231807148241371[36] = 0;
   out_9174231807148241371[37] = 0;
   out_9174231807148241371[38] = 0;
   out_9174231807148241371[39] = 0;
   out_9174231807148241371[40] = 0;
   out_9174231807148241371[41] = 0;
   out_9174231807148241371[42] = 0;
   out_9174231807148241371[43] = 0;
   out_9174231807148241371[44] = 1;
   out_9174231807148241371[45] = 0;
   out_9174231807148241371[46] = 0;
   out_9174231807148241371[47] = 0;
   out_9174231807148241371[48] = 0;
   out_9174231807148241371[49] = 0;
   out_9174231807148241371[50] = 0;
   out_9174231807148241371[51] = 0;
   out_9174231807148241371[52] = 0;
   out_9174231807148241371[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_7100903012294603026) {
  err_fun(nom_x, delta_x, out_7100903012294603026);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2844686309860313113) {
  inv_err_fun(nom_x, true_x, out_2844686309860313113);
}
void pose_H_mod_fun(double *state, double *out_4111323928338927612) {
  H_mod_fun(state, out_4111323928338927612);
}
void pose_f_fun(double *state, double dt, double *out_959899990977101830) {
  f_fun(state,  dt, out_959899990977101830);
}
void pose_F_fun(double *state, double dt, double *out_7787940412229259226) {
  F_fun(state,  dt, out_7787940412229259226);
}
void pose_h_4(double *state, double *unused, double *out_6652092636062505135) {
  h_4(state, unused, out_6652092636062505135);
}
void pose_H_4(double *state, double *unused, double *out_5309271410221825716) {
  H_4(state, unused, out_5309271410221825716);
}
void pose_h_10(double *state, double *unused, double *out_7011707270713003130) {
  h_10(state, unused, out_7011707270713003130);
}
void pose_H_10(double *state, double *unused, double *out_8349416150201841682) {
  H_10(state, unused, out_8349416150201841682);
}
void pose_h_13(double *state, double *unused, double *out_4264517865542995363) {
  h_13(state, unused, out_4264517865542995363);
}
void pose_H_13(double *state, double *unused, double *out_8521545235554158517) {
  H_13(state, unused, out_8521545235554158517);
}
void pose_h_14(double *state, double *unused, double *out_3869257689260825595) {
  h_14(state, unused, out_3869257689260825595);
}
void pose_H_14(double *state, double *unused, double *out_9174231807148241371) {
  H_14(state, unused, out_9174231807148241371);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
