#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_1581443076185256845);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3533335201823369929);
void car_H_mod_fun(double *state, double *out_3499608981558943551);
void car_f_fun(double *state, double dt, double *out_1821326269115237016);
void car_F_fun(double *state, double dt, double *out_7481865226501517041);
void car_h_25(double *state, double *unused, double *out_2738064975621769702);
void car_H_25(double *state, double *unused, double *out_4004943423759240263);
void car_h_24(double *state, double *unused, double *out_905360082965947707);
void car_H_24(double *state, double *unused, double *out_3534485941715901539);
void car_h_30(double *state, double *unused, double *out_4188696368250652869);
void car_H_30(double *state, double *unused, double *out_3875604476616000193);
void car_h_26(double *state, double *unused, double *out_5170780461585950981);
void car_H_26(double *state, double *unused, double *out_263440104885184039);
void car_h_27(double *state, double *unused, double *out_4911280197689564640);
void car_H_27(double *state, double *unused, double *out_1700841164815575282);
void car_h_29(double *state, double *unused, double *out_812976899410192776);
void car_H_29(double *state, double *unused, double *out_4385835820930392377);
void car_h_28(double *state, double *unused, double *out_7330025810757418666);
void car_H_28(double *state, double *unused, double *out_6349466092495718628);
void car_h_31(double *state, double *unused, double *out_4032770250728581234);
void car_H_31(double *state, double *unused, double *out_4035589385636200691);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}