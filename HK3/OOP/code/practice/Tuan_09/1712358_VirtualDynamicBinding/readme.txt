Nguyễn Minh Đức
1712358

Thưa thầy, do những con số của hàm random() rất lớn dẫn đến khó hiển thị số lượng gia súc sinh ngẫu nhiên 
trong bài 1 hay số hình trong bài 2 nên em đã chủ động giới hạn lại số sinh ngẫu nhiên này cho dễ kiểm tra.
Cụ thể:
- Ở bài 1: 
	+ số lượng gia súc ban đầu được giới hạn trong đoạn [5;10]
	+ hàm sinh con có giá trị trả về ngẫu nhiên được giới hạn trong đoạn [1;5]
	* lúc đầu em sẽ sinh ngẫu nhiên n gia súc, sau đó cứ mỗi gia súc em sẽ sinh ngẫu nhiên 1 số nữa để
	  để quyết định xem gia súc này là bò, cừu hay dê
	* khi lấy được giá trị trả về baby từ hàm HaveBaby() em đã tạo thêm baby con gia súc cùng loại vào Farm
- Ở bài 2:
	+ số lượng hình ban đầu được giới hạn trong đoạn [5;10]
	* lúc đầu em sẽ sinh ngẫu nhiên n hình, sau đó cứ mỗi hình em lại sinh ngẫu nhiên 1 số nữa để
	  để quyết định xem hình này là đường thẳng, hình chữ nhật hay elip