#ifndef _IO_H_
#define _IO_H_

#include <fstream>
#include <sstream>
#include <vector>
#include "qint.h"

//hàm xử lý chính, đầu vào là các string từ 1 dòng dữ liệu trong, trả về 1 string kết quả
string execute_data(vector<string> data);

//hàm tách 1 dòng từ file input thành nhiều string ngăn cách nhau bởi dấu cách
void split(string line, vector<string> & data);

//dòng dữ liệu từ file có các chỉ thị cơ số p1, p2, hàm này nhận vào các chỉ thị này ở dạng string và trả ra kết quả kiểu int. VD "10" thì trả ra 10
int get_base(string num);

#endif
