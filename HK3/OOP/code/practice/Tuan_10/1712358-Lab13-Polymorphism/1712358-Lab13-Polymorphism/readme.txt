Nguyễn Minh Đức 1712358

Bài em nộp thầy có thêm 1 file data.txt chứa dữ liệu ban đầu, em để thành file riêng cho dễ sửa dễ nhìn.

file data.txt này em đã để sẵn trong project 1 cái, trong file release 1 cái, việc xóa hay di dời file này đi
sẽ làm chương trình chạy không đúng, mong thầy lưu ý.

cấu trúc dữ liệu trong file data:
- dòng đầu tiên chứ số nguyên N là số lượng nhân viên.
- N cặp dòng liên tiếp tiếp theo:
  + dòng đầu chứa tên nhân viên.
  + dòng thứ 2 chứa liên tiếp 3 số nguyên: type, price_or_base, count_or_factor

type chỉ loại nhân viên, còn 2 biến còn lại là 2 biến đầu vào của hàm khởi tạo nên sẽ tùy loại nhân viên mà có
ý nghĩa khác nhau

type	Ý nghĩa			price_or_base	count_or_factor

1	ProductEmployee		ProductPrice	ProductCount
2	DailyEmployee		DailyPrice	DayCount
3	Manage			BaseSalary	SalaryFactor