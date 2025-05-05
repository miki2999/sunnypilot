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
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2343109546089990432) {
   out_2343109546089990432[0] = delta_x[0] + nom_x[0];
   out_2343109546089990432[1] = delta_x[1] + nom_x[1];
   out_2343109546089990432[2] = delta_x[2] + nom_x[2];
   out_2343109546089990432[3] = delta_x[3] + nom_x[3];
   out_2343109546089990432[4] = delta_x[4] + nom_x[4];
   out_2343109546089990432[5] = delta_x[5] + nom_x[5];
   out_2343109546089990432[6] = delta_x[6] + nom_x[6];
   out_2343109546089990432[7] = delta_x[7] + nom_x[7];
   out_2343109546089990432[8] = delta_x[8] + nom_x[8];
   out_2343109546089990432[9] = delta_x[9] + nom_x[9];
   out_2343109546089990432[10] = delta_x[10] + nom_x[10];
   out_2343109546089990432[11] = delta_x[11] + nom_x[11];
   out_2343109546089990432[12] = delta_x[12] + nom_x[12];
   out_2343109546089990432[13] = delta_x[13] + nom_x[13];
   out_2343109546089990432[14] = delta_x[14] + nom_x[14];
   out_2343109546089990432[15] = delta_x[15] + nom_x[15];
   out_2343109546089990432[16] = delta_x[16] + nom_x[16];
   out_2343109546089990432[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6250262588326011624) {
   out_6250262588326011624[0] = -nom_x[0] + true_x[0];
   out_6250262588326011624[1] = -nom_x[1] + true_x[1];
   out_6250262588326011624[2] = -nom_x[2] + true_x[2];
   out_6250262588326011624[3] = -nom_x[3] + true_x[3];
   out_6250262588326011624[4] = -nom_x[4] + true_x[4];
   out_6250262588326011624[5] = -nom_x[5] + true_x[5];
   out_6250262588326011624[6] = -nom_x[6] + true_x[6];
   out_6250262588326011624[7] = -nom_x[7] + true_x[7];
   out_6250262588326011624[8] = -nom_x[8] + true_x[8];
   out_6250262588326011624[9] = -nom_x[9] + true_x[9];
   out_6250262588326011624[10] = -nom_x[10] + true_x[10];
   out_6250262588326011624[11] = -nom_x[11] + true_x[11];
   out_6250262588326011624[12] = -nom_x[12] + true_x[12];
   out_6250262588326011624[13] = -nom_x[13] + true_x[13];
   out_6250262588326011624[14] = -nom_x[14] + true_x[14];
   out_6250262588326011624[15] = -nom_x[15] + true_x[15];
   out_6250262588326011624[16] = -nom_x[16] + true_x[16];
   out_6250262588326011624[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4730078843917365686) {
   out_4730078843917365686[0] = 1.0;
   out_4730078843917365686[1] = 0.0;
   out_4730078843917365686[2] = 0.0;
   out_4730078843917365686[3] = 0.0;
   out_4730078843917365686[4] = 0.0;
   out_4730078843917365686[5] = 0.0;
   out_4730078843917365686[6] = 0.0;
   out_4730078843917365686[7] = 0.0;
   out_4730078843917365686[8] = 0.0;
   out_4730078843917365686[9] = 0.0;
   out_4730078843917365686[10] = 0.0;
   out_4730078843917365686[11] = 0.0;
   out_4730078843917365686[12] = 0.0;
   out_4730078843917365686[13] = 0.0;
   out_4730078843917365686[14] = 0.0;
   out_4730078843917365686[15] = 0.0;
   out_4730078843917365686[16] = 0.0;
   out_4730078843917365686[17] = 0.0;
   out_4730078843917365686[18] = 0.0;
   out_4730078843917365686[19] = 1.0;
   out_4730078843917365686[20] = 0.0;
   out_4730078843917365686[21] = 0.0;
   out_4730078843917365686[22] = 0.0;
   out_4730078843917365686[23] = 0.0;
   out_4730078843917365686[24] = 0.0;
   out_4730078843917365686[25] = 0.0;
   out_4730078843917365686[26] = 0.0;
   out_4730078843917365686[27] = 0.0;
   out_4730078843917365686[28] = 0.0;
   out_4730078843917365686[29] = 0.0;
   out_4730078843917365686[30] = 0.0;
   out_4730078843917365686[31] = 0.0;
   out_4730078843917365686[32] = 0.0;
   out_4730078843917365686[33] = 0.0;
   out_4730078843917365686[34] = 0.0;
   out_4730078843917365686[35] = 0.0;
   out_4730078843917365686[36] = 0.0;
   out_4730078843917365686[37] = 0.0;
   out_4730078843917365686[38] = 1.0;
   out_4730078843917365686[39] = 0.0;
   out_4730078843917365686[40] = 0.0;
   out_4730078843917365686[41] = 0.0;
   out_4730078843917365686[42] = 0.0;
   out_4730078843917365686[43] = 0.0;
   out_4730078843917365686[44] = 0.0;
   out_4730078843917365686[45] = 0.0;
   out_4730078843917365686[46] = 0.0;
   out_4730078843917365686[47] = 0.0;
   out_4730078843917365686[48] = 0.0;
   out_4730078843917365686[49] = 0.0;
   out_4730078843917365686[50] = 0.0;
   out_4730078843917365686[51] = 0.0;
   out_4730078843917365686[52] = 0.0;
   out_4730078843917365686[53] = 0.0;
   out_4730078843917365686[54] = 0.0;
   out_4730078843917365686[55] = 0.0;
   out_4730078843917365686[56] = 0.0;
   out_4730078843917365686[57] = 1.0;
   out_4730078843917365686[58] = 0.0;
   out_4730078843917365686[59] = 0.0;
   out_4730078843917365686[60] = 0.0;
   out_4730078843917365686[61] = 0.0;
   out_4730078843917365686[62] = 0.0;
   out_4730078843917365686[63] = 0.0;
   out_4730078843917365686[64] = 0.0;
   out_4730078843917365686[65] = 0.0;
   out_4730078843917365686[66] = 0.0;
   out_4730078843917365686[67] = 0.0;
   out_4730078843917365686[68] = 0.0;
   out_4730078843917365686[69] = 0.0;
   out_4730078843917365686[70] = 0.0;
   out_4730078843917365686[71] = 0.0;
   out_4730078843917365686[72] = 0.0;
   out_4730078843917365686[73] = 0.0;
   out_4730078843917365686[74] = 0.0;
   out_4730078843917365686[75] = 0.0;
   out_4730078843917365686[76] = 1.0;
   out_4730078843917365686[77] = 0.0;
   out_4730078843917365686[78] = 0.0;
   out_4730078843917365686[79] = 0.0;
   out_4730078843917365686[80] = 0.0;
   out_4730078843917365686[81] = 0.0;
   out_4730078843917365686[82] = 0.0;
   out_4730078843917365686[83] = 0.0;
   out_4730078843917365686[84] = 0.0;
   out_4730078843917365686[85] = 0.0;
   out_4730078843917365686[86] = 0.0;
   out_4730078843917365686[87] = 0.0;
   out_4730078843917365686[88] = 0.0;
   out_4730078843917365686[89] = 0.0;
   out_4730078843917365686[90] = 0.0;
   out_4730078843917365686[91] = 0.0;
   out_4730078843917365686[92] = 0.0;
   out_4730078843917365686[93] = 0.0;
   out_4730078843917365686[94] = 0.0;
   out_4730078843917365686[95] = 1.0;
   out_4730078843917365686[96] = 0.0;
   out_4730078843917365686[97] = 0.0;
   out_4730078843917365686[98] = 0.0;
   out_4730078843917365686[99] = 0.0;
   out_4730078843917365686[100] = 0.0;
   out_4730078843917365686[101] = 0.0;
   out_4730078843917365686[102] = 0.0;
   out_4730078843917365686[103] = 0.0;
   out_4730078843917365686[104] = 0.0;
   out_4730078843917365686[105] = 0.0;
   out_4730078843917365686[106] = 0.0;
   out_4730078843917365686[107] = 0.0;
   out_4730078843917365686[108] = 0.0;
   out_4730078843917365686[109] = 0.0;
   out_4730078843917365686[110] = 0.0;
   out_4730078843917365686[111] = 0.0;
   out_4730078843917365686[112] = 0.0;
   out_4730078843917365686[113] = 0.0;
   out_4730078843917365686[114] = 1.0;
   out_4730078843917365686[115] = 0.0;
   out_4730078843917365686[116] = 0.0;
   out_4730078843917365686[117] = 0.0;
   out_4730078843917365686[118] = 0.0;
   out_4730078843917365686[119] = 0.0;
   out_4730078843917365686[120] = 0.0;
   out_4730078843917365686[121] = 0.0;
   out_4730078843917365686[122] = 0.0;
   out_4730078843917365686[123] = 0.0;
   out_4730078843917365686[124] = 0.0;
   out_4730078843917365686[125] = 0.0;
   out_4730078843917365686[126] = 0.0;
   out_4730078843917365686[127] = 0.0;
   out_4730078843917365686[128] = 0.0;
   out_4730078843917365686[129] = 0.0;
   out_4730078843917365686[130] = 0.0;
   out_4730078843917365686[131] = 0.0;
   out_4730078843917365686[132] = 0.0;
   out_4730078843917365686[133] = 1.0;
   out_4730078843917365686[134] = 0.0;
   out_4730078843917365686[135] = 0.0;
   out_4730078843917365686[136] = 0.0;
   out_4730078843917365686[137] = 0.0;
   out_4730078843917365686[138] = 0.0;
   out_4730078843917365686[139] = 0.0;
   out_4730078843917365686[140] = 0.0;
   out_4730078843917365686[141] = 0.0;
   out_4730078843917365686[142] = 0.0;
   out_4730078843917365686[143] = 0.0;
   out_4730078843917365686[144] = 0.0;
   out_4730078843917365686[145] = 0.0;
   out_4730078843917365686[146] = 0.0;
   out_4730078843917365686[147] = 0.0;
   out_4730078843917365686[148] = 0.0;
   out_4730078843917365686[149] = 0.0;
   out_4730078843917365686[150] = 0.0;
   out_4730078843917365686[151] = 0.0;
   out_4730078843917365686[152] = 1.0;
   out_4730078843917365686[153] = 0.0;
   out_4730078843917365686[154] = 0.0;
   out_4730078843917365686[155] = 0.0;
   out_4730078843917365686[156] = 0.0;
   out_4730078843917365686[157] = 0.0;
   out_4730078843917365686[158] = 0.0;
   out_4730078843917365686[159] = 0.0;
   out_4730078843917365686[160] = 0.0;
   out_4730078843917365686[161] = 0.0;
   out_4730078843917365686[162] = 0.0;
   out_4730078843917365686[163] = 0.0;
   out_4730078843917365686[164] = 0.0;
   out_4730078843917365686[165] = 0.0;
   out_4730078843917365686[166] = 0.0;
   out_4730078843917365686[167] = 0.0;
   out_4730078843917365686[168] = 0.0;
   out_4730078843917365686[169] = 0.0;
   out_4730078843917365686[170] = 0.0;
   out_4730078843917365686[171] = 1.0;
   out_4730078843917365686[172] = 0.0;
   out_4730078843917365686[173] = 0.0;
   out_4730078843917365686[174] = 0.0;
   out_4730078843917365686[175] = 0.0;
   out_4730078843917365686[176] = 0.0;
   out_4730078843917365686[177] = 0.0;
   out_4730078843917365686[178] = 0.0;
   out_4730078843917365686[179] = 0.0;
   out_4730078843917365686[180] = 0.0;
   out_4730078843917365686[181] = 0.0;
   out_4730078843917365686[182] = 0.0;
   out_4730078843917365686[183] = 0.0;
   out_4730078843917365686[184] = 0.0;
   out_4730078843917365686[185] = 0.0;
   out_4730078843917365686[186] = 0.0;
   out_4730078843917365686[187] = 0.0;
   out_4730078843917365686[188] = 0.0;
   out_4730078843917365686[189] = 0.0;
   out_4730078843917365686[190] = 1.0;
   out_4730078843917365686[191] = 0.0;
   out_4730078843917365686[192] = 0.0;
   out_4730078843917365686[193] = 0.0;
   out_4730078843917365686[194] = 0.0;
   out_4730078843917365686[195] = 0.0;
   out_4730078843917365686[196] = 0.0;
   out_4730078843917365686[197] = 0.0;
   out_4730078843917365686[198] = 0.0;
   out_4730078843917365686[199] = 0.0;
   out_4730078843917365686[200] = 0.0;
   out_4730078843917365686[201] = 0.0;
   out_4730078843917365686[202] = 0.0;
   out_4730078843917365686[203] = 0.0;
   out_4730078843917365686[204] = 0.0;
   out_4730078843917365686[205] = 0.0;
   out_4730078843917365686[206] = 0.0;
   out_4730078843917365686[207] = 0.0;
   out_4730078843917365686[208] = 0.0;
   out_4730078843917365686[209] = 1.0;
   out_4730078843917365686[210] = 0.0;
   out_4730078843917365686[211] = 0.0;
   out_4730078843917365686[212] = 0.0;
   out_4730078843917365686[213] = 0.0;
   out_4730078843917365686[214] = 0.0;
   out_4730078843917365686[215] = 0.0;
   out_4730078843917365686[216] = 0.0;
   out_4730078843917365686[217] = 0.0;
   out_4730078843917365686[218] = 0.0;
   out_4730078843917365686[219] = 0.0;
   out_4730078843917365686[220] = 0.0;
   out_4730078843917365686[221] = 0.0;
   out_4730078843917365686[222] = 0.0;
   out_4730078843917365686[223] = 0.0;
   out_4730078843917365686[224] = 0.0;
   out_4730078843917365686[225] = 0.0;
   out_4730078843917365686[226] = 0.0;
   out_4730078843917365686[227] = 0.0;
   out_4730078843917365686[228] = 1.0;
   out_4730078843917365686[229] = 0.0;
   out_4730078843917365686[230] = 0.0;
   out_4730078843917365686[231] = 0.0;
   out_4730078843917365686[232] = 0.0;
   out_4730078843917365686[233] = 0.0;
   out_4730078843917365686[234] = 0.0;
   out_4730078843917365686[235] = 0.0;
   out_4730078843917365686[236] = 0.0;
   out_4730078843917365686[237] = 0.0;
   out_4730078843917365686[238] = 0.0;
   out_4730078843917365686[239] = 0.0;
   out_4730078843917365686[240] = 0.0;
   out_4730078843917365686[241] = 0.0;
   out_4730078843917365686[242] = 0.0;
   out_4730078843917365686[243] = 0.0;
   out_4730078843917365686[244] = 0.0;
   out_4730078843917365686[245] = 0.0;
   out_4730078843917365686[246] = 0.0;
   out_4730078843917365686[247] = 1.0;
   out_4730078843917365686[248] = 0.0;
   out_4730078843917365686[249] = 0.0;
   out_4730078843917365686[250] = 0.0;
   out_4730078843917365686[251] = 0.0;
   out_4730078843917365686[252] = 0.0;
   out_4730078843917365686[253] = 0.0;
   out_4730078843917365686[254] = 0.0;
   out_4730078843917365686[255] = 0.0;
   out_4730078843917365686[256] = 0.0;
   out_4730078843917365686[257] = 0.0;
   out_4730078843917365686[258] = 0.0;
   out_4730078843917365686[259] = 0.0;
   out_4730078843917365686[260] = 0.0;
   out_4730078843917365686[261] = 0.0;
   out_4730078843917365686[262] = 0.0;
   out_4730078843917365686[263] = 0.0;
   out_4730078843917365686[264] = 0.0;
   out_4730078843917365686[265] = 0.0;
   out_4730078843917365686[266] = 1.0;
   out_4730078843917365686[267] = 0.0;
   out_4730078843917365686[268] = 0.0;
   out_4730078843917365686[269] = 0.0;
   out_4730078843917365686[270] = 0.0;
   out_4730078843917365686[271] = 0.0;
   out_4730078843917365686[272] = 0.0;
   out_4730078843917365686[273] = 0.0;
   out_4730078843917365686[274] = 0.0;
   out_4730078843917365686[275] = 0.0;
   out_4730078843917365686[276] = 0.0;
   out_4730078843917365686[277] = 0.0;
   out_4730078843917365686[278] = 0.0;
   out_4730078843917365686[279] = 0.0;
   out_4730078843917365686[280] = 0.0;
   out_4730078843917365686[281] = 0.0;
   out_4730078843917365686[282] = 0.0;
   out_4730078843917365686[283] = 0.0;
   out_4730078843917365686[284] = 0.0;
   out_4730078843917365686[285] = 1.0;
   out_4730078843917365686[286] = 0.0;
   out_4730078843917365686[287] = 0.0;
   out_4730078843917365686[288] = 0.0;
   out_4730078843917365686[289] = 0.0;
   out_4730078843917365686[290] = 0.0;
   out_4730078843917365686[291] = 0.0;
   out_4730078843917365686[292] = 0.0;
   out_4730078843917365686[293] = 0.0;
   out_4730078843917365686[294] = 0.0;
   out_4730078843917365686[295] = 0.0;
   out_4730078843917365686[296] = 0.0;
   out_4730078843917365686[297] = 0.0;
   out_4730078843917365686[298] = 0.0;
   out_4730078843917365686[299] = 0.0;
   out_4730078843917365686[300] = 0.0;
   out_4730078843917365686[301] = 0.0;
   out_4730078843917365686[302] = 0.0;
   out_4730078843917365686[303] = 0.0;
   out_4730078843917365686[304] = 1.0;
   out_4730078843917365686[305] = 0.0;
   out_4730078843917365686[306] = 0.0;
   out_4730078843917365686[307] = 0.0;
   out_4730078843917365686[308] = 0.0;
   out_4730078843917365686[309] = 0.0;
   out_4730078843917365686[310] = 0.0;
   out_4730078843917365686[311] = 0.0;
   out_4730078843917365686[312] = 0.0;
   out_4730078843917365686[313] = 0.0;
   out_4730078843917365686[314] = 0.0;
   out_4730078843917365686[315] = 0.0;
   out_4730078843917365686[316] = 0.0;
   out_4730078843917365686[317] = 0.0;
   out_4730078843917365686[318] = 0.0;
   out_4730078843917365686[319] = 0.0;
   out_4730078843917365686[320] = 0.0;
   out_4730078843917365686[321] = 0.0;
   out_4730078843917365686[322] = 0.0;
   out_4730078843917365686[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5266432288628039552) {
   out_5266432288628039552[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5266432288628039552[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5266432288628039552[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5266432288628039552[3] = dt*state[12] + state[3];
   out_5266432288628039552[4] = dt*state[13] + state[4];
   out_5266432288628039552[5] = dt*state[14] + state[5];
   out_5266432288628039552[6] = state[6];
   out_5266432288628039552[7] = state[7];
   out_5266432288628039552[8] = state[8];
   out_5266432288628039552[9] = state[9];
   out_5266432288628039552[10] = state[10];
   out_5266432288628039552[11] = state[11];
   out_5266432288628039552[12] = state[12];
   out_5266432288628039552[13] = state[13];
   out_5266432288628039552[14] = state[14];
   out_5266432288628039552[15] = state[15];
   out_5266432288628039552[16] = state[16];
   out_5266432288628039552[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6430483000299200317) {
   out_6430483000299200317[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6430483000299200317[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6430483000299200317[2] = 0;
   out_6430483000299200317[3] = 0;
   out_6430483000299200317[4] = 0;
   out_6430483000299200317[5] = 0;
   out_6430483000299200317[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6430483000299200317[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6430483000299200317[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6430483000299200317[9] = 0;
   out_6430483000299200317[10] = 0;
   out_6430483000299200317[11] = 0;
   out_6430483000299200317[12] = 0;
   out_6430483000299200317[13] = 0;
   out_6430483000299200317[14] = 0;
   out_6430483000299200317[15] = 0;
   out_6430483000299200317[16] = 0;
   out_6430483000299200317[17] = 0;
   out_6430483000299200317[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6430483000299200317[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6430483000299200317[20] = 0;
   out_6430483000299200317[21] = 0;
   out_6430483000299200317[22] = 0;
   out_6430483000299200317[23] = 0;
   out_6430483000299200317[24] = 0;
   out_6430483000299200317[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6430483000299200317[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6430483000299200317[27] = 0;
   out_6430483000299200317[28] = 0;
   out_6430483000299200317[29] = 0;
   out_6430483000299200317[30] = 0;
   out_6430483000299200317[31] = 0;
   out_6430483000299200317[32] = 0;
   out_6430483000299200317[33] = 0;
   out_6430483000299200317[34] = 0;
   out_6430483000299200317[35] = 0;
   out_6430483000299200317[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6430483000299200317[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6430483000299200317[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6430483000299200317[39] = 0;
   out_6430483000299200317[40] = 0;
   out_6430483000299200317[41] = 0;
   out_6430483000299200317[42] = 0;
   out_6430483000299200317[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6430483000299200317[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6430483000299200317[45] = 0;
   out_6430483000299200317[46] = 0;
   out_6430483000299200317[47] = 0;
   out_6430483000299200317[48] = 0;
   out_6430483000299200317[49] = 0;
   out_6430483000299200317[50] = 0;
   out_6430483000299200317[51] = 0;
   out_6430483000299200317[52] = 0;
   out_6430483000299200317[53] = 0;
   out_6430483000299200317[54] = 0;
   out_6430483000299200317[55] = 0;
   out_6430483000299200317[56] = 0;
   out_6430483000299200317[57] = 1;
   out_6430483000299200317[58] = 0;
   out_6430483000299200317[59] = 0;
   out_6430483000299200317[60] = 0;
   out_6430483000299200317[61] = 0;
   out_6430483000299200317[62] = 0;
   out_6430483000299200317[63] = 0;
   out_6430483000299200317[64] = 0;
   out_6430483000299200317[65] = 0;
   out_6430483000299200317[66] = dt;
   out_6430483000299200317[67] = 0;
   out_6430483000299200317[68] = 0;
   out_6430483000299200317[69] = 0;
   out_6430483000299200317[70] = 0;
   out_6430483000299200317[71] = 0;
   out_6430483000299200317[72] = 0;
   out_6430483000299200317[73] = 0;
   out_6430483000299200317[74] = 0;
   out_6430483000299200317[75] = 0;
   out_6430483000299200317[76] = 1;
   out_6430483000299200317[77] = 0;
   out_6430483000299200317[78] = 0;
   out_6430483000299200317[79] = 0;
   out_6430483000299200317[80] = 0;
   out_6430483000299200317[81] = 0;
   out_6430483000299200317[82] = 0;
   out_6430483000299200317[83] = 0;
   out_6430483000299200317[84] = 0;
   out_6430483000299200317[85] = dt;
   out_6430483000299200317[86] = 0;
   out_6430483000299200317[87] = 0;
   out_6430483000299200317[88] = 0;
   out_6430483000299200317[89] = 0;
   out_6430483000299200317[90] = 0;
   out_6430483000299200317[91] = 0;
   out_6430483000299200317[92] = 0;
   out_6430483000299200317[93] = 0;
   out_6430483000299200317[94] = 0;
   out_6430483000299200317[95] = 1;
   out_6430483000299200317[96] = 0;
   out_6430483000299200317[97] = 0;
   out_6430483000299200317[98] = 0;
   out_6430483000299200317[99] = 0;
   out_6430483000299200317[100] = 0;
   out_6430483000299200317[101] = 0;
   out_6430483000299200317[102] = 0;
   out_6430483000299200317[103] = 0;
   out_6430483000299200317[104] = dt;
   out_6430483000299200317[105] = 0;
   out_6430483000299200317[106] = 0;
   out_6430483000299200317[107] = 0;
   out_6430483000299200317[108] = 0;
   out_6430483000299200317[109] = 0;
   out_6430483000299200317[110] = 0;
   out_6430483000299200317[111] = 0;
   out_6430483000299200317[112] = 0;
   out_6430483000299200317[113] = 0;
   out_6430483000299200317[114] = 1;
   out_6430483000299200317[115] = 0;
   out_6430483000299200317[116] = 0;
   out_6430483000299200317[117] = 0;
   out_6430483000299200317[118] = 0;
   out_6430483000299200317[119] = 0;
   out_6430483000299200317[120] = 0;
   out_6430483000299200317[121] = 0;
   out_6430483000299200317[122] = 0;
   out_6430483000299200317[123] = 0;
   out_6430483000299200317[124] = 0;
   out_6430483000299200317[125] = 0;
   out_6430483000299200317[126] = 0;
   out_6430483000299200317[127] = 0;
   out_6430483000299200317[128] = 0;
   out_6430483000299200317[129] = 0;
   out_6430483000299200317[130] = 0;
   out_6430483000299200317[131] = 0;
   out_6430483000299200317[132] = 0;
   out_6430483000299200317[133] = 1;
   out_6430483000299200317[134] = 0;
   out_6430483000299200317[135] = 0;
   out_6430483000299200317[136] = 0;
   out_6430483000299200317[137] = 0;
   out_6430483000299200317[138] = 0;
   out_6430483000299200317[139] = 0;
   out_6430483000299200317[140] = 0;
   out_6430483000299200317[141] = 0;
   out_6430483000299200317[142] = 0;
   out_6430483000299200317[143] = 0;
   out_6430483000299200317[144] = 0;
   out_6430483000299200317[145] = 0;
   out_6430483000299200317[146] = 0;
   out_6430483000299200317[147] = 0;
   out_6430483000299200317[148] = 0;
   out_6430483000299200317[149] = 0;
   out_6430483000299200317[150] = 0;
   out_6430483000299200317[151] = 0;
   out_6430483000299200317[152] = 1;
   out_6430483000299200317[153] = 0;
   out_6430483000299200317[154] = 0;
   out_6430483000299200317[155] = 0;
   out_6430483000299200317[156] = 0;
   out_6430483000299200317[157] = 0;
   out_6430483000299200317[158] = 0;
   out_6430483000299200317[159] = 0;
   out_6430483000299200317[160] = 0;
   out_6430483000299200317[161] = 0;
   out_6430483000299200317[162] = 0;
   out_6430483000299200317[163] = 0;
   out_6430483000299200317[164] = 0;
   out_6430483000299200317[165] = 0;
   out_6430483000299200317[166] = 0;
   out_6430483000299200317[167] = 0;
   out_6430483000299200317[168] = 0;
   out_6430483000299200317[169] = 0;
   out_6430483000299200317[170] = 0;
   out_6430483000299200317[171] = 1;
   out_6430483000299200317[172] = 0;
   out_6430483000299200317[173] = 0;
   out_6430483000299200317[174] = 0;
   out_6430483000299200317[175] = 0;
   out_6430483000299200317[176] = 0;
   out_6430483000299200317[177] = 0;
   out_6430483000299200317[178] = 0;
   out_6430483000299200317[179] = 0;
   out_6430483000299200317[180] = 0;
   out_6430483000299200317[181] = 0;
   out_6430483000299200317[182] = 0;
   out_6430483000299200317[183] = 0;
   out_6430483000299200317[184] = 0;
   out_6430483000299200317[185] = 0;
   out_6430483000299200317[186] = 0;
   out_6430483000299200317[187] = 0;
   out_6430483000299200317[188] = 0;
   out_6430483000299200317[189] = 0;
   out_6430483000299200317[190] = 1;
   out_6430483000299200317[191] = 0;
   out_6430483000299200317[192] = 0;
   out_6430483000299200317[193] = 0;
   out_6430483000299200317[194] = 0;
   out_6430483000299200317[195] = 0;
   out_6430483000299200317[196] = 0;
   out_6430483000299200317[197] = 0;
   out_6430483000299200317[198] = 0;
   out_6430483000299200317[199] = 0;
   out_6430483000299200317[200] = 0;
   out_6430483000299200317[201] = 0;
   out_6430483000299200317[202] = 0;
   out_6430483000299200317[203] = 0;
   out_6430483000299200317[204] = 0;
   out_6430483000299200317[205] = 0;
   out_6430483000299200317[206] = 0;
   out_6430483000299200317[207] = 0;
   out_6430483000299200317[208] = 0;
   out_6430483000299200317[209] = 1;
   out_6430483000299200317[210] = 0;
   out_6430483000299200317[211] = 0;
   out_6430483000299200317[212] = 0;
   out_6430483000299200317[213] = 0;
   out_6430483000299200317[214] = 0;
   out_6430483000299200317[215] = 0;
   out_6430483000299200317[216] = 0;
   out_6430483000299200317[217] = 0;
   out_6430483000299200317[218] = 0;
   out_6430483000299200317[219] = 0;
   out_6430483000299200317[220] = 0;
   out_6430483000299200317[221] = 0;
   out_6430483000299200317[222] = 0;
   out_6430483000299200317[223] = 0;
   out_6430483000299200317[224] = 0;
   out_6430483000299200317[225] = 0;
   out_6430483000299200317[226] = 0;
   out_6430483000299200317[227] = 0;
   out_6430483000299200317[228] = 1;
   out_6430483000299200317[229] = 0;
   out_6430483000299200317[230] = 0;
   out_6430483000299200317[231] = 0;
   out_6430483000299200317[232] = 0;
   out_6430483000299200317[233] = 0;
   out_6430483000299200317[234] = 0;
   out_6430483000299200317[235] = 0;
   out_6430483000299200317[236] = 0;
   out_6430483000299200317[237] = 0;
   out_6430483000299200317[238] = 0;
   out_6430483000299200317[239] = 0;
   out_6430483000299200317[240] = 0;
   out_6430483000299200317[241] = 0;
   out_6430483000299200317[242] = 0;
   out_6430483000299200317[243] = 0;
   out_6430483000299200317[244] = 0;
   out_6430483000299200317[245] = 0;
   out_6430483000299200317[246] = 0;
   out_6430483000299200317[247] = 1;
   out_6430483000299200317[248] = 0;
   out_6430483000299200317[249] = 0;
   out_6430483000299200317[250] = 0;
   out_6430483000299200317[251] = 0;
   out_6430483000299200317[252] = 0;
   out_6430483000299200317[253] = 0;
   out_6430483000299200317[254] = 0;
   out_6430483000299200317[255] = 0;
   out_6430483000299200317[256] = 0;
   out_6430483000299200317[257] = 0;
   out_6430483000299200317[258] = 0;
   out_6430483000299200317[259] = 0;
   out_6430483000299200317[260] = 0;
   out_6430483000299200317[261] = 0;
   out_6430483000299200317[262] = 0;
   out_6430483000299200317[263] = 0;
   out_6430483000299200317[264] = 0;
   out_6430483000299200317[265] = 0;
   out_6430483000299200317[266] = 1;
   out_6430483000299200317[267] = 0;
   out_6430483000299200317[268] = 0;
   out_6430483000299200317[269] = 0;
   out_6430483000299200317[270] = 0;
   out_6430483000299200317[271] = 0;
   out_6430483000299200317[272] = 0;
   out_6430483000299200317[273] = 0;
   out_6430483000299200317[274] = 0;
   out_6430483000299200317[275] = 0;
   out_6430483000299200317[276] = 0;
   out_6430483000299200317[277] = 0;
   out_6430483000299200317[278] = 0;
   out_6430483000299200317[279] = 0;
   out_6430483000299200317[280] = 0;
   out_6430483000299200317[281] = 0;
   out_6430483000299200317[282] = 0;
   out_6430483000299200317[283] = 0;
   out_6430483000299200317[284] = 0;
   out_6430483000299200317[285] = 1;
   out_6430483000299200317[286] = 0;
   out_6430483000299200317[287] = 0;
   out_6430483000299200317[288] = 0;
   out_6430483000299200317[289] = 0;
   out_6430483000299200317[290] = 0;
   out_6430483000299200317[291] = 0;
   out_6430483000299200317[292] = 0;
   out_6430483000299200317[293] = 0;
   out_6430483000299200317[294] = 0;
   out_6430483000299200317[295] = 0;
   out_6430483000299200317[296] = 0;
   out_6430483000299200317[297] = 0;
   out_6430483000299200317[298] = 0;
   out_6430483000299200317[299] = 0;
   out_6430483000299200317[300] = 0;
   out_6430483000299200317[301] = 0;
   out_6430483000299200317[302] = 0;
   out_6430483000299200317[303] = 0;
   out_6430483000299200317[304] = 1;
   out_6430483000299200317[305] = 0;
   out_6430483000299200317[306] = 0;
   out_6430483000299200317[307] = 0;
   out_6430483000299200317[308] = 0;
   out_6430483000299200317[309] = 0;
   out_6430483000299200317[310] = 0;
   out_6430483000299200317[311] = 0;
   out_6430483000299200317[312] = 0;
   out_6430483000299200317[313] = 0;
   out_6430483000299200317[314] = 0;
   out_6430483000299200317[315] = 0;
   out_6430483000299200317[316] = 0;
   out_6430483000299200317[317] = 0;
   out_6430483000299200317[318] = 0;
   out_6430483000299200317[319] = 0;
   out_6430483000299200317[320] = 0;
   out_6430483000299200317[321] = 0;
   out_6430483000299200317[322] = 0;
   out_6430483000299200317[323] = 1;
}
void h_4(double *state, double *unused, double *out_5871837789572178941) {
   out_5871837789572178941[0] = state[6] + state[9];
   out_5871837789572178941[1] = state[7] + state[10];
   out_5871837789572178941[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_5928026325800263790) {
   out_5928026325800263790[0] = 0;
   out_5928026325800263790[1] = 0;
   out_5928026325800263790[2] = 0;
   out_5928026325800263790[3] = 0;
   out_5928026325800263790[4] = 0;
   out_5928026325800263790[5] = 0;
   out_5928026325800263790[6] = 1;
   out_5928026325800263790[7] = 0;
   out_5928026325800263790[8] = 0;
   out_5928026325800263790[9] = 1;
   out_5928026325800263790[10] = 0;
   out_5928026325800263790[11] = 0;
   out_5928026325800263790[12] = 0;
   out_5928026325800263790[13] = 0;
   out_5928026325800263790[14] = 0;
   out_5928026325800263790[15] = 0;
   out_5928026325800263790[16] = 0;
   out_5928026325800263790[17] = 0;
   out_5928026325800263790[18] = 0;
   out_5928026325800263790[19] = 0;
   out_5928026325800263790[20] = 0;
   out_5928026325800263790[21] = 0;
   out_5928026325800263790[22] = 0;
   out_5928026325800263790[23] = 0;
   out_5928026325800263790[24] = 0;
   out_5928026325800263790[25] = 1;
   out_5928026325800263790[26] = 0;
   out_5928026325800263790[27] = 0;
   out_5928026325800263790[28] = 1;
   out_5928026325800263790[29] = 0;
   out_5928026325800263790[30] = 0;
   out_5928026325800263790[31] = 0;
   out_5928026325800263790[32] = 0;
   out_5928026325800263790[33] = 0;
   out_5928026325800263790[34] = 0;
   out_5928026325800263790[35] = 0;
   out_5928026325800263790[36] = 0;
   out_5928026325800263790[37] = 0;
   out_5928026325800263790[38] = 0;
   out_5928026325800263790[39] = 0;
   out_5928026325800263790[40] = 0;
   out_5928026325800263790[41] = 0;
   out_5928026325800263790[42] = 0;
   out_5928026325800263790[43] = 0;
   out_5928026325800263790[44] = 1;
   out_5928026325800263790[45] = 0;
   out_5928026325800263790[46] = 0;
   out_5928026325800263790[47] = 1;
   out_5928026325800263790[48] = 0;
   out_5928026325800263790[49] = 0;
   out_5928026325800263790[50] = 0;
   out_5928026325800263790[51] = 0;
   out_5928026325800263790[52] = 0;
   out_5928026325800263790[53] = 0;
}
void h_10(double *state, double *unused, double *out_4831208843302909645) {
   out_4831208843302909645[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4831208843302909645[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4831208843302909645[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3150410560262957570) {
   out_3150410560262957570[0] = 0;
   out_3150410560262957570[1] = 9.8100000000000005*cos(state[1]);
   out_3150410560262957570[2] = 0;
   out_3150410560262957570[3] = 0;
   out_3150410560262957570[4] = -state[8];
   out_3150410560262957570[5] = state[7];
   out_3150410560262957570[6] = 0;
   out_3150410560262957570[7] = state[5];
   out_3150410560262957570[8] = -state[4];
   out_3150410560262957570[9] = 0;
   out_3150410560262957570[10] = 0;
   out_3150410560262957570[11] = 0;
   out_3150410560262957570[12] = 1;
   out_3150410560262957570[13] = 0;
   out_3150410560262957570[14] = 0;
   out_3150410560262957570[15] = 1;
   out_3150410560262957570[16] = 0;
   out_3150410560262957570[17] = 0;
   out_3150410560262957570[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3150410560262957570[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3150410560262957570[20] = 0;
   out_3150410560262957570[21] = state[8];
   out_3150410560262957570[22] = 0;
   out_3150410560262957570[23] = -state[6];
   out_3150410560262957570[24] = -state[5];
   out_3150410560262957570[25] = 0;
   out_3150410560262957570[26] = state[3];
   out_3150410560262957570[27] = 0;
   out_3150410560262957570[28] = 0;
   out_3150410560262957570[29] = 0;
   out_3150410560262957570[30] = 0;
   out_3150410560262957570[31] = 1;
   out_3150410560262957570[32] = 0;
   out_3150410560262957570[33] = 0;
   out_3150410560262957570[34] = 1;
   out_3150410560262957570[35] = 0;
   out_3150410560262957570[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3150410560262957570[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3150410560262957570[38] = 0;
   out_3150410560262957570[39] = -state[7];
   out_3150410560262957570[40] = state[6];
   out_3150410560262957570[41] = 0;
   out_3150410560262957570[42] = state[4];
   out_3150410560262957570[43] = -state[3];
   out_3150410560262957570[44] = 0;
   out_3150410560262957570[45] = 0;
   out_3150410560262957570[46] = 0;
   out_3150410560262957570[47] = 0;
   out_3150410560262957570[48] = 0;
   out_3150410560262957570[49] = 0;
   out_3150410560262957570[50] = 1;
   out_3150410560262957570[51] = 0;
   out_3150410560262957570[52] = 0;
   out_3150410560262957570[53] = 1;
}
void h_13(double *state, double *unused, double *out_3542107992820507541) {
   out_3542107992820507541[0] = state[3];
   out_3542107992820507541[1] = state[4];
   out_3542107992820507541[2] = state[5];
}
void H_13(double *state, double *unused, double *out_9140300151132596591) {
   out_9140300151132596591[0] = 0;
   out_9140300151132596591[1] = 0;
   out_9140300151132596591[2] = 0;
   out_9140300151132596591[3] = 1;
   out_9140300151132596591[4] = 0;
   out_9140300151132596591[5] = 0;
   out_9140300151132596591[6] = 0;
   out_9140300151132596591[7] = 0;
   out_9140300151132596591[8] = 0;
   out_9140300151132596591[9] = 0;
   out_9140300151132596591[10] = 0;
   out_9140300151132596591[11] = 0;
   out_9140300151132596591[12] = 0;
   out_9140300151132596591[13] = 0;
   out_9140300151132596591[14] = 0;
   out_9140300151132596591[15] = 0;
   out_9140300151132596591[16] = 0;
   out_9140300151132596591[17] = 0;
   out_9140300151132596591[18] = 0;
   out_9140300151132596591[19] = 0;
   out_9140300151132596591[20] = 0;
   out_9140300151132596591[21] = 0;
   out_9140300151132596591[22] = 1;
   out_9140300151132596591[23] = 0;
   out_9140300151132596591[24] = 0;
   out_9140300151132596591[25] = 0;
   out_9140300151132596591[26] = 0;
   out_9140300151132596591[27] = 0;
   out_9140300151132596591[28] = 0;
   out_9140300151132596591[29] = 0;
   out_9140300151132596591[30] = 0;
   out_9140300151132596591[31] = 0;
   out_9140300151132596591[32] = 0;
   out_9140300151132596591[33] = 0;
   out_9140300151132596591[34] = 0;
   out_9140300151132596591[35] = 0;
   out_9140300151132596591[36] = 0;
   out_9140300151132596591[37] = 0;
   out_9140300151132596591[38] = 0;
   out_9140300151132596591[39] = 0;
   out_9140300151132596591[40] = 0;
   out_9140300151132596591[41] = 1;
   out_9140300151132596591[42] = 0;
   out_9140300151132596591[43] = 0;
   out_9140300151132596591[44] = 0;
   out_9140300151132596591[45] = 0;
   out_9140300151132596591[46] = 0;
   out_9140300151132596591[47] = 0;
   out_9140300151132596591[48] = 0;
   out_9140300151132596591[49] = 0;
   out_9140300151132596591[50] = 0;
   out_9140300151132596591[51] = 0;
   out_9140300151132596591[52] = 0;
   out_9140300151132596591[53] = 0;
}
void h_14(double *state, double *unused, double *out_129812995230636672) {
   out_129812995230636672[0] = state[6];
   out_129812995230636672[1] = state[7];
   out_129812995230636672[2] = state[8];
}
void H_14(double *state, double *unused, double *out_8555476891569803297) {
   out_8555476891569803297[0] = 0;
   out_8555476891569803297[1] = 0;
   out_8555476891569803297[2] = 0;
   out_8555476891569803297[3] = 0;
   out_8555476891569803297[4] = 0;
   out_8555476891569803297[5] = 0;
   out_8555476891569803297[6] = 1;
   out_8555476891569803297[7] = 0;
   out_8555476891569803297[8] = 0;
   out_8555476891569803297[9] = 0;
   out_8555476891569803297[10] = 0;
   out_8555476891569803297[11] = 0;
   out_8555476891569803297[12] = 0;
   out_8555476891569803297[13] = 0;
   out_8555476891569803297[14] = 0;
   out_8555476891569803297[15] = 0;
   out_8555476891569803297[16] = 0;
   out_8555476891569803297[17] = 0;
   out_8555476891569803297[18] = 0;
   out_8555476891569803297[19] = 0;
   out_8555476891569803297[20] = 0;
   out_8555476891569803297[21] = 0;
   out_8555476891569803297[22] = 0;
   out_8555476891569803297[23] = 0;
   out_8555476891569803297[24] = 0;
   out_8555476891569803297[25] = 1;
   out_8555476891569803297[26] = 0;
   out_8555476891569803297[27] = 0;
   out_8555476891569803297[28] = 0;
   out_8555476891569803297[29] = 0;
   out_8555476891569803297[30] = 0;
   out_8555476891569803297[31] = 0;
   out_8555476891569803297[32] = 0;
   out_8555476891569803297[33] = 0;
   out_8555476891569803297[34] = 0;
   out_8555476891569803297[35] = 0;
   out_8555476891569803297[36] = 0;
   out_8555476891569803297[37] = 0;
   out_8555476891569803297[38] = 0;
   out_8555476891569803297[39] = 0;
   out_8555476891569803297[40] = 0;
   out_8555476891569803297[41] = 0;
   out_8555476891569803297[42] = 0;
   out_8555476891569803297[43] = 0;
   out_8555476891569803297[44] = 1;
   out_8555476891569803297[45] = 0;
   out_8555476891569803297[46] = 0;
   out_8555476891569803297[47] = 0;
   out_8555476891569803297[48] = 0;
   out_8555476891569803297[49] = 0;
   out_8555476891569803297[50] = 0;
   out_8555476891569803297[51] = 0;
   out_8555476891569803297[52] = 0;
   out_8555476891569803297[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_2343109546089990432) {
  err_fun(nom_x, delta_x, out_2343109546089990432);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6250262588326011624) {
  inv_err_fun(nom_x, true_x, out_6250262588326011624);
}
void pose_H_mod_fun(double *state, double *out_4730078843917365686) {
  H_mod_fun(state, out_4730078843917365686);
}
void pose_f_fun(double *state, double dt, double *out_5266432288628039552) {
  f_fun(state,  dt, out_5266432288628039552);
}
void pose_F_fun(double *state, double dt, double *out_6430483000299200317) {
  F_fun(state,  dt, out_6430483000299200317);
}
void pose_h_4(double *state, double *unused, double *out_5871837789572178941) {
  h_4(state, unused, out_5871837789572178941);
}
void pose_H_4(double *state, double *unused, double *out_5928026325800263790) {
  H_4(state, unused, out_5928026325800263790);
}
void pose_h_10(double *state, double *unused, double *out_4831208843302909645) {
  h_10(state, unused, out_4831208843302909645);
}
void pose_H_10(double *state, double *unused, double *out_3150410560262957570) {
  H_10(state, unused, out_3150410560262957570);
}
void pose_h_13(double *state, double *unused, double *out_3542107992820507541) {
  h_13(state, unused, out_3542107992820507541);
}
void pose_H_13(double *state, double *unused, double *out_9140300151132596591) {
  H_13(state, unused, out_9140300151132596591);
}
void pose_h_14(double *state, double *unused, double *out_129812995230636672) {
  h_14(state, unused, out_129812995230636672);
}
void pose_H_14(double *state, double *unused, double *out_8555476891569803297) {
  H_14(state, unused, out_8555476891569803297);
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
