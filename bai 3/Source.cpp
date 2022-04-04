#include "Time.h"
void main()
{
	TIME moc_thoi_gian[10000];
	int so_luong;
	Input_Time(moc_thoi_gian, so_luong);
	cout << "--------------------\n";
	for (int i = 0; i < so_luong; i++) {
		moc_thoi_gian[i].Output_bissextile();
	}
	cout << "--------------------\n";
	for (int i = 0; i < so_luong; i++) {
		cout << "Nhap giay them vao cho ngay " << i+1 << endl;
		moc_thoi_gian[i].Change_second_to_hour_minute_second();
		cout << endl;
	}

}