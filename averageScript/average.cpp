/**
 * @file average.cpp
 * @author Rose Richards (rose.evelyn5550@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-02-25
 * 
 * @copyright Copyright (c) 2026
 * 
 */

 double average(double x[], double y){
    double z = 0;
    for (int i = 0; i < y;i++){
        z = z + x[i];
    }
    return z / y;
 }