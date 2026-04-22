#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_7100903012294603026);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2844686309860313113);
void pose_H_mod_fun(double *state, double *out_4111323928338927612);
void pose_f_fun(double *state, double dt, double *out_959899990977101830);
void pose_F_fun(double *state, double dt, double *out_7787940412229259226);
void pose_h_4(double *state, double *unused, double *out_6652092636062505135);
void pose_H_4(double *state, double *unused, double *out_5309271410221825716);
void pose_h_10(double *state, double *unused, double *out_7011707270713003130);
void pose_H_10(double *state, double *unused, double *out_8349416150201841682);
void pose_h_13(double *state, double *unused, double *out_4264517865542995363);
void pose_H_13(double *state, double *unused, double *out_8521545235554158517);
void pose_h_14(double *state, double *unused, double *out_3869257689260825595);
void pose_H_14(double *state, double *unused, double *out_9174231807148241371);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}