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
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1581443076185256845) {
   out_1581443076185256845[0] = delta_x[0] + nom_x[0];
   out_1581443076185256845[1] = delta_x[1] + nom_x[1];
   out_1581443076185256845[2] = delta_x[2] + nom_x[2];
   out_1581443076185256845[3] = delta_x[3] + nom_x[3];
   out_1581443076185256845[4] = delta_x[4] + nom_x[4];
   out_1581443076185256845[5] = delta_x[5] + nom_x[5];
   out_1581443076185256845[6] = delta_x[6] + nom_x[6];
   out_1581443076185256845[7] = delta_x[7] + nom_x[7];
   out_1581443076185256845[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3533335201823369929) {
   out_3533335201823369929[0] = -nom_x[0] + true_x[0];
   out_3533335201823369929[1] = -nom_x[1] + true_x[1];
   out_3533335201823369929[2] = -nom_x[2] + true_x[2];
   out_3533335201823369929[3] = -nom_x[3] + true_x[3];
   out_3533335201823369929[4] = -nom_x[4] + true_x[4];
   out_3533335201823369929[5] = -nom_x[5] + true_x[5];
   out_3533335201823369929[6] = -nom_x[6] + true_x[6];
   out_3533335201823369929[7] = -nom_x[7] + true_x[7];
   out_3533335201823369929[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3499608981558943551) {
   out_3499608981558943551[0] = 1.0;
   out_3499608981558943551[1] = 0.0;
   out_3499608981558943551[2] = 0.0;
   out_3499608981558943551[3] = 0.0;
   out_3499608981558943551[4] = 0.0;
   out_3499608981558943551[5] = 0.0;
   out_3499608981558943551[6] = 0.0;
   out_3499608981558943551[7] = 0.0;
   out_3499608981558943551[8] = 0.0;
   out_3499608981558943551[9] = 0.0;
   out_3499608981558943551[10] = 1.0;
   out_3499608981558943551[11] = 0.0;
   out_3499608981558943551[12] = 0.0;
   out_3499608981558943551[13] = 0.0;
   out_3499608981558943551[14] = 0.0;
   out_3499608981558943551[15] = 0.0;
   out_3499608981558943551[16] = 0.0;
   out_3499608981558943551[17] = 0.0;
   out_3499608981558943551[18] = 0.0;
   out_3499608981558943551[19] = 0.0;
   out_3499608981558943551[20] = 1.0;
   out_3499608981558943551[21] = 0.0;
   out_3499608981558943551[22] = 0.0;
   out_3499608981558943551[23] = 0.0;
   out_3499608981558943551[24] = 0.0;
   out_3499608981558943551[25] = 0.0;
   out_3499608981558943551[26] = 0.0;
   out_3499608981558943551[27] = 0.0;
   out_3499608981558943551[28] = 0.0;
   out_3499608981558943551[29] = 0.0;
   out_3499608981558943551[30] = 1.0;
   out_3499608981558943551[31] = 0.0;
   out_3499608981558943551[32] = 0.0;
   out_3499608981558943551[33] = 0.0;
   out_3499608981558943551[34] = 0.0;
   out_3499608981558943551[35] = 0.0;
   out_3499608981558943551[36] = 0.0;
   out_3499608981558943551[37] = 0.0;
   out_3499608981558943551[38] = 0.0;
   out_3499608981558943551[39] = 0.0;
   out_3499608981558943551[40] = 1.0;
   out_3499608981558943551[41] = 0.0;
   out_3499608981558943551[42] = 0.0;
   out_3499608981558943551[43] = 0.0;
   out_3499608981558943551[44] = 0.0;
   out_3499608981558943551[45] = 0.0;
   out_3499608981558943551[46] = 0.0;
   out_3499608981558943551[47] = 0.0;
   out_3499608981558943551[48] = 0.0;
   out_3499608981558943551[49] = 0.0;
   out_3499608981558943551[50] = 1.0;
   out_3499608981558943551[51] = 0.0;
   out_3499608981558943551[52] = 0.0;
   out_3499608981558943551[53] = 0.0;
   out_3499608981558943551[54] = 0.0;
   out_3499608981558943551[55] = 0.0;
   out_3499608981558943551[56] = 0.0;
   out_3499608981558943551[57] = 0.0;
   out_3499608981558943551[58] = 0.0;
   out_3499608981558943551[59] = 0.0;
   out_3499608981558943551[60] = 1.0;
   out_3499608981558943551[61] = 0.0;
   out_3499608981558943551[62] = 0.0;
   out_3499608981558943551[63] = 0.0;
   out_3499608981558943551[64] = 0.0;
   out_3499608981558943551[65] = 0.0;
   out_3499608981558943551[66] = 0.0;
   out_3499608981558943551[67] = 0.0;
   out_3499608981558943551[68] = 0.0;
   out_3499608981558943551[69] = 0.0;
   out_3499608981558943551[70] = 1.0;
   out_3499608981558943551[71] = 0.0;
   out_3499608981558943551[72] = 0.0;
   out_3499608981558943551[73] = 0.0;
   out_3499608981558943551[74] = 0.0;
   out_3499608981558943551[75] = 0.0;
   out_3499608981558943551[76] = 0.0;
   out_3499608981558943551[77] = 0.0;
   out_3499608981558943551[78] = 0.0;
   out_3499608981558943551[79] = 0.0;
   out_3499608981558943551[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1821326269115237016) {
   out_1821326269115237016[0] = state[0];
   out_1821326269115237016[1] = state[1];
   out_1821326269115237016[2] = state[2];
   out_1821326269115237016[3] = state[3];
   out_1821326269115237016[4] = state[4];
   out_1821326269115237016[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1821326269115237016[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1821326269115237016[7] = state[7];
   out_1821326269115237016[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7481865226501517041) {
   out_7481865226501517041[0] = 1;
   out_7481865226501517041[1] = 0;
   out_7481865226501517041[2] = 0;
   out_7481865226501517041[3] = 0;
   out_7481865226501517041[4] = 0;
   out_7481865226501517041[5] = 0;
   out_7481865226501517041[6] = 0;
   out_7481865226501517041[7] = 0;
   out_7481865226501517041[8] = 0;
   out_7481865226501517041[9] = 0;
   out_7481865226501517041[10] = 1;
   out_7481865226501517041[11] = 0;
   out_7481865226501517041[12] = 0;
   out_7481865226501517041[13] = 0;
   out_7481865226501517041[14] = 0;
   out_7481865226501517041[15] = 0;
   out_7481865226501517041[16] = 0;
   out_7481865226501517041[17] = 0;
   out_7481865226501517041[18] = 0;
   out_7481865226501517041[19] = 0;
   out_7481865226501517041[20] = 1;
   out_7481865226501517041[21] = 0;
   out_7481865226501517041[22] = 0;
   out_7481865226501517041[23] = 0;
   out_7481865226501517041[24] = 0;
   out_7481865226501517041[25] = 0;
   out_7481865226501517041[26] = 0;
   out_7481865226501517041[27] = 0;
   out_7481865226501517041[28] = 0;
   out_7481865226501517041[29] = 0;
   out_7481865226501517041[30] = 1;
   out_7481865226501517041[31] = 0;
   out_7481865226501517041[32] = 0;
   out_7481865226501517041[33] = 0;
   out_7481865226501517041[34] = 0;
   out_7481865226501517041[35] = 0;
   out_7481865226501517041[36] = 0;
   out_7481865226501517041[37] = 0;
   out_7481865226501517041[38] = 0;
   out_7481865226501517041[39] = 0;
   out_7481865226501517041[40] = 1;
   out_7481865226501517041[41] = 0;
   out_7481865226501517041[42] = 0;
   out_7481865226501517041[43] = 0;
   out_7481865226501517041[44] = 0;
   out_7481865226501517041[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7481865226501517041[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7481865226501517041[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7481865226501517041[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7481865226501517041[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7481865226501517041[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7481865226501517041[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7481865226501517041[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7481865226501517041[53] = -9.8100000000000005*dt;
   out_7481865226501517041[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7481865226501517041[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7481865226501517041[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7481865226501517041[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7481865226501517041[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7481865226501517041[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7481865226501517041[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7481865226501517041[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7481865226501517041[62] = 0;
   out_7481865226501517041[63] = 0;
   out_7481865226501517041[64] = 0;
   out_7481865226501517041[65] = 0;
   out_7481865226501517041[66] = 0;
   out_7481865226501517041[67] = 0;
   out_7481865226501517041[68] = 0;
   out_7481865226501517041[69] = 0;
   out_7481865226501517041[70] = 1;
   out_7481865226501517041[71] = 0;
   out_7481865226501517041[72] = 0;
   out_7481865226501517041[73] = 0;
   out_7481865226501517041[74] = 0;
   out_7481865226501517041[75] = 0;
   out_7481865226501517041[76] = 0;
   out_7481865226501517041[77] = 0;
   out_7481865226501517041[78] = 0;
   out_7481865226501517041[79] = 0;
   out_7481865226501517041[80] = 1;
}
void h_25(double *state, double *unused, double *out_2738064975621769702) {
   out_2738064975621769702[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4004943423759240263) {
   out_4004943423759240263[0] = 0;
   out_4004943423759240263[1] = 0;
   out_4004943423759240263[2] = 0;
   out_4004943423759240263[3] = 0;
   out_4004943423759240263[4] = 0;
   out_4004943423759240263[5] = 0;
   out_4004943423759240263[6] = 1;
   out_4004943423759240263[7] = 0;
   out_4004943423759240263[8] = 0;
}
void h_24(double *state, double *unused, double *out_905360082965947707) {
   out_905360082965947707[0] = state[4];
   out_905360082965947707[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3534485941715901539) {
   out_3534485941715901539[0] = 0;
   out_3534485941715901539[1] = 0;
   out_3534485941715901539[2] = 0;
   out_3534485941715901539[3] = 0;
   out_3534485941715901539[4] = 1;
   out_3534485941715901539[5] = 0;
   out_3534485941715901539[6] = 0;
   out_3534485941715901539[7] = 0;
   out_3534485941715901539[8] = 0;
   out_3534485941715901539[9] = 0;
   out_3534485941715901539[10] = 0;
   out_3534485941715901539[11] = 0;
   out_3534485941715901539[12] = 0;
   out_3534485941715901539[13] = 0;
   out_3534485941715901539[14] = 1;
   out_3534485941715901539[15] = 0;
   out_3534485941715901539[16] = 0;
   out_3534485941715901539[17] = 0;
}
void h_30(double *state, double *unused, double *out_4188696368250652869) {
   out_4188696368250652869[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3875604476616000193) {
   out_3875604476616000193[0] = 0;
   out_3875604476616000193[1] = 0;
   out_3875604476616000193[2] = 0;
   out_3875604476616000193[3] = 0;
   out_3875604476616000193[4] = 1;
   out_3875604476616000193[5] = 0;
   out_3875604476616000193[6] = 0;
   out_3875604476616000193[7] = 0;
   out_3875604476616000193[8] = 0;
}
void h_26(double *state, double *unused, double *out_5170780461585950981) {
   out_5170780461585950981[0] = state[7];
}
void H_26(double *state, double *unused, double *out_263440104885184039) {
   out_263440104885184039[0] = 0;
   out_263440104885184039[1] = 0;
   out_263440104885184039[2] = 0;
   out_263440104885184039[3] = 0;
   out_263440104885184039[4] = 0;
   out_263440104885184039[5] = 0;
   out_263440104885184039[6] = 0;
   out_263440104885184039[7] = 1;
   out_263440104885184039[8] = 0;
}
void h_27(double *state, double *unused, double *out_4911280197689564640) {
   out_4911280197689564640[0] = state[3];
}
void H_27(double *state, double *unused, double *out_1700841164815575282) {
   out_1700841164815575282[0] = 0;
   out_1700841164815575282[1] = 0;
   out_1700841164815575282[2] = 0;
   out_1700841164815575282[3] = 1;
   out_1700841164815575282[4] = 0;
   out_1700841164815575282[5] = 0;
   out_1700841164815575282[6] = 0;
   out_1700841164815575282[7] = 0;
   out_1700841164815575282[8] = 0;
}
void h_29(double *state, double *unused, double *out_812976899410192776) {
   out_812976899410192776[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4385835820930392377) {
   out_4385835820930392377[0] = 0;
   out_4385835820930392377[1] = 1;
   out_4385835820930392377[2] = 0;
   out_4385835820930392377[3] = 0;
   out_4385835820930392377[4] = 0;
   out_4385835820930392377[5] = 0;
   out_4385835820930392377[6] = 0;
   out_4385835820930392377[7] = 0;
   out_4385835820930392377[8] = 0;
}
void h_28(double *state, double *unused, double *out_7330025810757418666) {
   out_7330025810757418666[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6349466092495718628) {
   out_6349466092495718628[0] = 1;
   out_6349466092495718628[1] = 0;
   out_6349466092495718628[2] = 0;
   out_6349466092495718628[3] = 0;
   out_6349466092495718628[4] = 0;
   out_6349466092495718628[5] = 0;
   out_6349466092495718628[6] = 0;
   out_6349466092495718628[7] = 0;
   out_6349466092495718628[8] = 0;
}
void h_31(double *state, double *unused, double *out_4032770250728581234) {
   out_4032770250728581234[0] = state[8];
}
void H_31(double *state, double *unused, double *out_4035589385636200691) {
   out_4035589385636200691[0] = 0;
   out_4035589385636200691[1] = 0;
   out_4035589385636200691[2] = 0;
   out_4035589385636200691[3] = 0;
   out_4035589385636200691[4] = 0;
   out_4035589385636200691[5] = 0;
   out_4035589385636200691[6] = 0;
   out_4035589385636200691[7] = 0;
   out_4035589385636200691[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_1581443076185256845) {
  err_fun(nom_x, delta_x, out_1581443076185256845);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3533335201823369929) {
  inv_err_fun(nom_x, true_x, out_3533335201823369929);
}
void car_H_mod_fun(double *state, double *out_3499608981558943551) {
  H_mod_fun(state, out_3499608981558943551);
}
void car_f_fun(double *state, double dt, double *out_1821326269115237016) {
  f_fun(state,  dt, out_1821326269115237016);
}
void car_F_fun(double *state, double dt, double *out_7481865226501517041) {
  F_fun(state,  dt, out_7481865226501517041);
}
void car_h_25(double *state, double *unused, double *out_2738064975621769702) {
  h_25(state, unused, out_2738064975621769702);
}
void car_H_25(double *state, double *unused, double *out_4004943423759240263) {
  H_25(state, unused, out_4004943423759240263);
}
void car_h_24(double *state, double *unused, double *out_905360082965947707) {
  h_24(state, unused, out_905360082965947707);
}
void car_H_24(double *state, double *unused, double *out_3534485941715901539) {
  H_24(state, unused, out_3534485941715901539);
}
void car_h_30(double *state, double *unused, double *out_4188696368250652869) {
  h_30(state, unused, out_4188696368250652869);
}
void car_H_30(double *state, double *unused, double *out_3875604476616000193) {
  H_30(state, unused, out_3875604476616000193);
}
void car_h_26(double *state, double *unused, double *out_5170780461585950981) {
  h_26(state, unused, out_5170780461585950981);
}
void car_H_26(double *state, double *unused, double *out_263440104885184039) {
  H_26(state, unused, out_263440104885184039);
}
void car_h_27(double *state, double *unused, double *out_4911280197689564640) {
  h_27(state, unused, out_4911280197689564640);
}
void car_H_27(double *state, double *unused, double *out_1700841164815575282) {
  H_27(state, unused, out_1700841164815575282);
}
void car_h_29(double *state, double *unused, double *out_812976899410192776) {
  h_29(state, unused, out_812976899410192776);
}
void car_H_29(double *state, double *unused, double *out_4385835820930392377) {
  H_29(state, unused, out_4385835820930392377);
}
void car_h_28(double *state, double *unused, double *out_7330025810757418666) {
  h_28(state, unused, out_7330025810757418666);
}
void car_H_28(double *state, double *unused, double *out_6349466092495718628) {
  H_28(state, unused, out_6349466092495718628);
}
void car_h_31(double *state, double *unused, double *out_4032770250728581234) {
  h_31(state, unused, out_4032770250728581234);
}
void car_H_31(double *state, double *unused, double *out_4035589385636200691) {
  H_31(state, unused, out_4035589385636200691);
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
