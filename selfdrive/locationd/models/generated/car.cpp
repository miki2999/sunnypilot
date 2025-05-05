#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8107402288870890641) {
   out_8107402288870890641[0] = delta_x[0] + nom_x[0];
   out_8107402288870890641[1] = delta_x[1] + nom_x[1];
   out_8107402288870890641[2] = delta_x[2] + nom_x[2];
   out_8107402288870890641[3] = delta_x[3] + nom_x[3];
   out_8107402288870890641[4] = delta_x[4] + nom_x[4];
   out_8107402288870890641[5] = delta_x[5] + nom_x[5];
   out_8107402288870890641[6] = delta_x[6] + nom_x[6];
   out_8107402288870890641[7] = delta_x[7] + nom_x[7];
   out_8107402288870890641[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5433981207053307034) {
   out_5433981207053307034[0] = -nom_x[0] + true_x[0];
   out_5433981207053307034[1] = -nom_x[1] + true_x[1];
   out_5433981207053307034[2] = -nom_x[2] + true_x[2];
   out_5433981207053307034[3] = -nom_x[3] + true_x[3];
   out_5433981207053307034[4] = -nom_x[4] + true_x[4];
   out_5433981207053307034[5] = -nom_x[5] + true_x[5];
   out_5433981207053307034[6] = -nom_x[6] + true_x[6];
   out_5433981207053307034[7] = -nom_x[7] + true_x[7];
   out_5433981207053307034[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5608734284886803167) {
   out_5608734284886803167[0] = 1.0;
   out_5608734284886803167[1] = 0.0;
   out_5608734284886803167[2] = 0.0;
   out_5608734284886803167[3] = 0.0;
   out_5608734284886803167[4] = 0.0;
   out_5608734284886803167[5] = 0.0;
   out_5608734284886803167[6] = 0.0;
   out_5608734284886803167[7] = 0.0;
   out_5608734284886803167[8] = 0.0;
   out_5608734284886803167[9] = 0.0;
   out_5608734284886803167[10] = 1.0;
   out_5608734284886803167[11] = 0.0;
   out_5608734284886803167[12] = 0.0;
   out_5608734284886803167[13] = 0.0;
   out_5608734284886803167[14] = 0.0;
   out_5608734284886803167[15] = 0.0;
   out_5608734284886803167[16] = 0.0;
   out_5608734284886803167[17] = 0.0;
   out_5608734284886803167[18] = 0.0;
   out_5608734284886803167[19] = 0.0;
   out_5608734284886803167[20] = 1.0;
   out_5608734284886803167[21] = 0.0;
   out_5608734284886803167[22] = 0.0;
   out_5608734284886803167[23] = 0.0;
   out_5608734284886803167[24] = 0.0;
   out_5608734284886803167[25] = 0.0;
   out_5608734284886803167[26] = 0.0;
   out_5608734284886803167[27] = 0.0;
   out_5608734284886803167[28] = 0.0;
   out_5608734284886803167[29] = 0.0;
   out_5608734284886803167[30] = 1.0;
   out_5608734284886803167[31] = 0.0;
   out_5608734284886803167[32] = 0.0;
   out_5608734284886803167[33] = 0.0;
   out_5608734284886803167[34] = 0.0;
   out_5608734284886803167[35] = 0.0;
   out_5608734284886803167[36] = 0.0;
   out_5608734284886803167[37] = 0.0;
   out_5608734284886803167[38] = 0.0;
   out_5608734284886803167[39] = 0.0;
   out_5608734284886803167[40] = 1.0;
   out_5608734284886803167[41] = 0.0;
   out_5608734284886803167[42] = 0.0;
   out_5608734284886803167[43] = 0.0;
   out_5608734284886803167[44] = 0.0;
   out_5608734284886803167[45] = 0.0;
   out_5608734284886803167[46] = 0.0;
   out_5608734284886803167[47] = 0.0;
   out_5608734284886803167[48] = 0.0;
   out_5608734284886803167[49] = 0.0;
   out_5608734284886803167[50] = 1.0;
   out_5608734284886803167[51] = 0.0;
   out_5608734284886803167[52] = 0.0;
   out_5608734284886803167[53] = 0.0;
   out_5608734284886803167[54] = 0.0;
   out_5608734284886803167[55] = 0.0;
   out_5608734284886803167[56] = 0.0;
   out_5608734284886803167[57] = 0.0;
   out_5608734284886803167[58] = 0.0;
   out_5608734284886803167[59] = 0.0;
   out_5608734284886803167[60] = 1.0;
   out_5608734284886803167[61] = 0.0;
   out_5608734284886803167[62] = 0.0;
   out_5608734284886803167[63] = 0.0;
   out_5608734284886803167[64] = 0.0;
   out_5608734284886803167[65] = 0.0;
   out_5608734284886803167[66] = 0.0;
   out_5608734284886803167[67] = 0.0;
   out_5608734284886803167[68] = 0.0;
   out_5608734284886803167[69] = 0.0;
   out_5608734284886803167[70] = 1.0;
   out_5608734284886803167[71] = 0.0;
   out_5608734284886803167[72] = 0.0;
   out_5608734284886803167[73] = 0.0;
   out_5608734284886803167[74] = 0.0;
   out_5608734284886803167[75] = 0.0;
   out_5608734284886803167[76] = 0.0;
   out_5608734284886803167[77] = 0.0;
   out_5608734284886803167[78] = 0.0;
   out_5608734284886803167[79] = 0.0;
   out_5608734284886803167[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7445832192269672811) {
   out_7445832192269672811[0] = state[0];
   out_7445832192269672811[1] = state[1];
   out_7445832192269672811[2] = state[2];
   out_7445832192269672811[3] = state[3];
   out_7445832192269672811[4] = state[4];
   out_7445832192269672811[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7445832192269672811[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7445832192269672811[7] = state[7];
   out_7445832192269672811[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5342856672650676645) {
   out_5342856672650676645[0] = 1;
   out_5342856672650676645[1] = 0;
   out_5342856672650676645[2] = 0;
   out_5342856672650676645[3] = 0;
   out_5342856672650676645[4] = 0;
   out_5342856672650676645[5] = 0;
   out_5342856672650676645[6] = 0;
   out_5342856672650676645[7] = 0;
   out_5342856672650676645[8] = 0;
   out_5342856672650676645[9] = 0;
   out_5342856672650676645[10] = 1;
   out_5342856672650676645[11] = 0;
   out_5342856672650676645[12] = 0;
   out_5342856672650676645[13] = 0;
   out_5342856672650676645[14] = 0;
   out_5342856672650676645[15] = 0;
   out_5342856672650676645[16] = 0;
   out_5342856672650676645[17] = 0;
   out_5342856672650676645[18] = 0;
   out_5342856672650676645[19] = 0;
   out_5342856672650676645[20] = 1;
   out_5342856672650676645[21] = 0;
   out_5342856672650676645[22] = 0;
   out_5342856672650676645[23] = 0;
   out_5342856672650676645[24] = 0;
   out_5342856672650676645[25] = 0;
   out_5342856672650676645[26] = 0;
   out_5342856672650676645[27] = 0;
   out_5342856672650676645[28] = 0;
   out_5342856672650676645[29] = 0;
   out_5342856672650676645[30] = 1;
   out_5342856672650676645[31] = 0;
   out_5342856672650676645[32] = 0;
   out_5342856672650676645[33] = 0;
   out_5342856672650676645[34] = 0;
   out_5342856672650676645[35] = 0;
   out_5342856672650676645[36] = 0;
   out_5342856672650676645[37] = 0;
   out_5342856672650676645[38] = 0;
   out_5342856672650676645[39] = 0;
   out_5342856672650676645[40] = 1;
   out_5342856672650676645[41] = 0;
   out_5342856672650676645[42] = 0;
   out_5342856672650676645[43] = 0;
   out_5342856672650676645[44] = 0;
   out_5342856672650676645[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5342856672650676645[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5342856672650676645[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5342856672650676645[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5342856672650676645[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5342856672650676645[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5342856672650676645[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5342856672650676645[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5342856672650676645[53] = -9.8000000000000007*dt;
   out_5342856672650676645[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5342856672650676645[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5342856672650676645[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5342856672650676645[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5342856672650676645[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5342856672650676645[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5342856672650676645[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5342856672650676645[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5342856672650676645[62] = 0;
   out_5342856672650676645[63] = 0;
   out_5342856672650676645[64] = 0;
   out_5342856672650676645[65] = 0;
   out_5342856672650676645[66] = 0;
   out_5342856672650676645[67] = 0;
   out_5342856672650676645[68] = 0;
   out_5342856672650676645[69] = 0;
   out_5342856672650676645[70] = 1;
   out_5342856672650676645[71] = 0;
   out_5342856672650676645[72] = 0;
   out_5342856672650676645[73] = 0;
   out_5342856672650676645[74] = 0;
   out_5342856672650676645[75] = 0;
   out_5342856672650676645[76] = 0;
   out_5342856672650676645[77] = 0;
   out_5342856672650676645[78] = 0;
   out_5342856672650676645[79] = 0;
   out_5342856672650676645[80] = 1;
}
void h_25(double *state, double *unused, double *out_7238616735344798765) {
   out_7238616735344798765[0] = state[6];
}
void H_25(double *state, double *unused, double *out_705042459702138327) {
   out_705042459702138327[0] = 0;
   out_705042459702138327[1] = 0;
   out_705042459702138327[2] = 0;
   out_705042459702138327[3] = 0;
   out_705042459702138327[4] = 0;
   out_705042459702138327[5] = 0;
   out_705042459702138327[6] = 1;
   out_705042459702138327[7] = 0;
   out_705042459702138327[8] = 0;
}
void h_24(double *state, double *unused, double *out_5548209659854666404) {
   out_5548209659854666404[0] = state[4];
   out_5548209659854666404[1] = state[5];
}
void H_24(double *state, double *unused, double *out_4568451823210874267) {
   out_4568451823210874267[0] = 0;
   out_4568451823210874267[1] = 0;
   out_4568451823210874267[2] = 0;
   out_4568451823210874267[3] = 0;
   out_4568451823210874267[4] = 1;
   out_4568451823210874267[5] = 0;
   out_4568451823210874267[6] = 0;
   out_4568451823210874267[7] = 0;
   out_4568451823210874267[8] = 0;
   out_4568451823210874267[9] = 0;
   out_4568451823210874267[10] = 0;
   out_4568451823210874267[11] = 0;
   out_4568451823210874267[12] = 0;
   out_4568451823210874267[13] = 0;
   out_4568451823210874267[14] = 1;
   out_4568451823210874267[15] = 0;
   out_4568451823210874267[16] = 0;
   out_4568451823210874267[17] = 0;
}
void h_30(double *state, double *unused, double *out_1258043945918941227) {
   out_1258043945918941227[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1813290498805110300) {
   out_1813290498805110300[0] = 0;
   out_1813290498805110300[1] = 0;
   out_1813290498805110300[2] = 0;
   out_1813290498805110300[3] = 0;
   out_1813290498805110300[4] = 1;
   out_1813290498805110300[5] = 0;
   out_1813290498805110300[6] = 0;
   out_1813290498805110300[7] = 0;
   out_1813290498805110300[8] = 0;
}
void h_26(double *state, double *unused, double *out_6177099488509759586) {
   out_6177099488509759586[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4446545778576194551) {
   out_4446545778576194551[0] = 0;
   out_4446545778576194551[1] = 0;
   out_4446545778576194551[2] = 0;
   out_4446545778576194551[3] = 0;
   out_4446545778576194551[4] = 0;
   out_4446545778576194551[5] = 0;
   out_4446545778576194551[6] = 0;
   out_4446545778576194551[7] = 1;
   out_4446545778576194551[8] = 0;
}
void h_27(double *state, double *unused, double *out_6063237275249105314) {
   out_6063237275249105314[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3009144718645803308) {
   out_3009144718645803308[0] = 0;
   out_3009144718645803308[1] = 0;
   out_3009144718645803308[2] = 0;
   out_3009144718645803308[3] = 1;
   out_3009144718645803308[4] = 0;
   out_3009144718645803308[5] = 0;
   out_3009144718645803308[6] = 0;
   out_3009144718645803308[7] = 0;
   out_3009144718645803308[8] = 0;
}
void h_29(double *state, double *unused, double *out_2201553798820603662) {
   out_2201553798820603662[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2323521843119502484) {
   out_2323521843119502484[0] = 0;
   out_2323521843119502484[1] = 1;
   out_2323521843119502484[2] = 0;
   out_2323521843119502484[3] = 0;
   out_2323521843119502484[4] = 0;
   out_2323521843119502484[5] = 0;
   out_2323521843119502484[6] = 0;
   out_2323521843119502484[7] = 0;
   out_2323521843119502484[8] = 0;
}
void h_28(double *state, double *unused, double *out_1140036551985564483) {
   out_1140036551985564483[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2758877173950028090) {
   out_2758877173950028090[0] = 1;
   out_2758877173950028090[1] = 0;
   out_2758877173950028090[2] = 0;
   out_2758877173950028090[3] = 0;
   out_2758877173950028090[4] = 0;
   out_2758877173950028090[5] = 0;
   out_2758877173950028090[6] = 0;
   out_2758877173950028090[7] = 0;
   out_2758877173950028090[8] = 0;
}
void h_31(double *state, double *unused, double *out_794005604323305494) {
   out_794005604323305494[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5072753880809546027) {
   out_5072753880809546027[0] = 0;
   out_5072753880809546027[1] = 0;
   out_5072753880809546027[2] = 0;
   out_5072753880809546027[3] = 0;
   out_5072753880809546027[4] = 0;
   out_5072753880809546027[5] = 0;
   out_5072753880809546027[6] = 0;
   out_5072753880809546027[7] = 0;
   out_5072753880809546027[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_8107402288870890641) {
  err_fun(nom_x, delta_x, out_8107402288870890641);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5433981207053307034) {
  inv_err_fun(nom_x, true_x, out_5433981207053307034);
}
void car_H_mod_fun(double *state, double *out_5608734284886803167) {
  H_mod_fun(state, out_5608734284886803167);
}
void car_f_fun(double *state, double dt, double *out_7445832192269672811) {
  f_fun(state,  dt, out_7445832192269672811);
}
void car_F_fun(double *state, double dt, double *out_5342856672650676645) {
  F_fun(state,  dt, out_5342856672650676645);
}
void car_h_25(double *state, double *unused, double *out_7238616735344798765) {
  h_25(state, unused, out_7238616735344798765);
}
void car_H_25(double *state, double *unused, double *out_705042459702138327) {
  H_25(state, unused, out_705042459702138327);
}
void car_h_24(double *state, double *unused, double *out_5548209659854666404) {
  h_24(state, unused, out_5548209659854666404);
}
void car_H_24(double *state, double *unused, double *out_4568451823210874267) {
  H_24(state, unused, out_4568451823210874267);
}
void car_h_30(double *state, double *unused, double *out_1258043945918941227) {
  h_30(state, unused, out_1258043945918941227);
}
void car_H_30(double *state, double *unused, double *out_1813290498805110300) {
  H_30(state, unused, out_1813290498805110300);
}
void car_h_26(double *state, double *unused, double *out_6177099488509759586) {
  h_26(state, unused, out_6177099488509759586);
}
void car_H_26(double *state, double *unused, double *out_4446545778576194551) {
  H_26(state, unused, out_4446545778576194551);
}
void car_h_27(double *state, double *unused, double *out_6063237275249105314) {
  h_27(state, unused, out_6063237275249105314);
}
void car_H_27(double *state, double *unused, double *out_3009144718645803308) {
  H_27(state, unused, out_3009144718645803308);
}
void car_h_29(double *state, double *unused, double *out_2201553798820603662) {
  h_29(state, unused, out_2201553798820603662);
}
void car_H_29(double *state, double *unused, double *out_2323521843119502484) {
  H_29(state, unused, out_2323521843119502484);
}
void car_h_28(double *state, double *unused, double *out_1140036551985564483) {
  h_28(state, unused, out_1140036551985564483);
}
void car_H_28(double *state, double *unused, double *out_2758877173950028090) {
  H_28(state, unused, out_2758877173950028090);
}
void car_h_31(double *state, double *unused, double *out_794005604323305494) {
  h_31(state, unused, out_794005604323305494);
}
void car_H_31(double *state, double *unused, double *out_5072753880809546027) {
  H_31(state, unused, out_5072753880809546027);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
