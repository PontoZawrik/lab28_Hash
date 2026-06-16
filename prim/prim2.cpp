//#include <iostream>
//#include <string>
//using namespace std;
//
//unsigned int hesh_function(string str, int key_hesh, int count_symbols) {
//	unsigned int size = pow(10, count_symbols);
//	unsigned long long int hesh_code, tmp_hesh = 0;
//
//	for (size_t i = 0; i < str.length(); i++) {
//		tmp_hesh += (int)pow(key_hesh, i) * (int)(str[i]);
//		tmp_hesh = tmp_hesh % size;
//	}
//	hesh_code = tmp_hesh & size;
//	return hesh_code;
//}
//
//int main() {
//	int key_hesh = 11;
//	int count_symbols = 9;
//
//	string str1 = "wqweqwrqwr";
//	string str2 = "wqweqwrqwr";
//
//	cout << "String: " << str1 << " hesh code to this string: " << hesh_function(str1, key_hesh, count_symbols) << endl;
//	cout << "String: " << str2 << " hesh code to this string: " << hesh_function(str2, key_hesh, count_symbols) << endl;
//
//	system("pause");
//	return 0;
//}