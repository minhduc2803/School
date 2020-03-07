CREATE DATABASE QLDETAI

USE QLDETAI

CREATE TABLE GIAOVIEN
(
	MAGV varchar(5),
	HOTEN nvarchar(40),
	LUONG Float,
	PHAI nvarchar(3),
	NGSINH date,
	DIACHI nvarchar(100),
	GVQLCM varchar(5),
	MABM nvarchar(5)
	PRIMARY KEY(MAGV)
)

CREATE TABLE GV_DT 
(
	MAGV varchar(5),
	DIENTHOAI varchar(12)
	PRIMARY KEY(MAGV, DIENTHOAI)
)

CREATE TABLE BOMON
(
	MABM nvarchar(5),
	TENBM nvarchar(40),
	PHONG varchar(5),
	DIENTHOAI varchar(12),
	TRUONGBM varchar(5),
	MAKHOA varchar(4),
	NGAYNHANCHUC date
	PRIMARY KEY(MABM)
)

CREATE TABLE KHOA
(
	MAKHOA varchar(4),
	TENKHOA nvarchar(40),
	NAMTL Int,
	PHONG varchar(5),
	DIENTHOAI varchar(12),
	TRUONGKHOA varchar(5),
	NGAYNHANCHUC date
	PRIMARY KEY(MAKHOA)
)

CREATE TABLE DETAI
(
	MADT varchar(3),
	TENDT nvarchar(100),
	CAPQL nvarchar(40),
	KINHPHI Float,
	NGAYBD date,
	NGAYKT date,
	MACD nvarchar(4),
	GVCNDT varchar(5)
	PRIMARY KEY(MADT)
)

CREATE TABLE CHUDE
(
	MACD nvarchar(4),
	TENCD nvarchar(50)
	PRIMARY KEY(MACD)
)

CREATE TABLE CONGVIEC
(
	MADT varchar(3),
	SOTT Int,
	TENCV nvarchar(40),
	NGAYBD date,
	NGAYKT date
	PRIMARY KEY(MADT, SOTT)
)

CREATE TABLE THAMGIADT
(
	MAGV varchar(5),
	MADT varchar(3),
	STT Int,
	PHUCAP Float ,
	KETQUA nvarchar(40)
	PRIMARY KEY(MAGV, MADT, STT)
)

CREATE TABLE NGUOITHAN
(
	MAGV varchar(5),
	TEN nvarchar(20),
	NGSINH date,
	PHAI nvarchar(3)
	PRIMARY KEY(MAGV, TEN)
)

ALTER TABLE THAMGIADT
ADD CONSTRAINT FK_THAMGIADT_CONGIVEC
FOREIGN KEY(MADT, STT)
REFERENCES CONGVIEC(MADT, SOTT)

ALTER TABLE THAMGIADT
ADD CONSTRAINT FK_THAMGIADT_GIAOVIEN
FOREIGN KEY(MAGV)
REFERENCES GIAOVIEN(MAGV)

ALTER TABLE CONGVIEC
ADD CONSTRAINT FK_CONGVIEC_DETAI
FOREIGN KEY(MADT)
REFERENCES DETAI(MADT)

ALTER TABLE DETAI
ADD CONSTRAINT FK_DETAI_CHUDE
FOREIGN KEY(MACD)
REFERENCES CHUDE(MACD)

ALTER TABLE DETAI
ADD CONSTRAINT KF_DETAI_GIAOVIEN
FOREIGN KEY(GVCNDT)
REFERENCES GIAOVIEN(MAGV)

ALTER TABLE KHOA
ADD CONSTRAINT FK_KHOA_GIAOVIEN
FOREIGN KEY(TRUONGKHOA)
REFERENCES GIAOVIEN(MAGV)

ALTER TABLE BOMON
ADD CONSTRAINT FK_BOMON_KHOA
FOREIGN KEY(MAKHOA)
REFERENCES KHOA(MAKHOA)

ALTER TABLE BOMON
ADD CONSTRAINT FK_BOMON_GIAOVIEN
FOREIGN KEY(TRUONGBM)
REFERENCES GIAOVIEN(MAGV)

ALTER TABLE GIAOVIEN
ADD CONSTRAINT FK_GIAOVIEN_BOMON
FOREIGN KEY(MABM)
REFERENCES BOMON(MABM)

ALTER TABLE GIAOVIEN
ADD CONSTRAINT FK_GIAOVIEN_GIAOVIEN
FOREIGN KEY(MAGV)
REFERENCES GIAOVIEN(MAGV)

ALTER TABLE GV_DT
ADD CONSTRAINT FK_GV_DT_GIAOVIEN
FOREIGN KEY(MAGV)
REFERENCES GIAOVIEN(MAGV)

ALTER TABLE NGUOITHAN
ADD CONSTRAINT FK_NGUOITHAN_GIAOVIEN
FOREIGN KEY(MAGV)
REFERENCES GIAOVIEN(MAGV)

INSERT INTO GIAOVIEN VALUES ('001',N'Nguyễn Hoài An',2000.0,'Nam','1973-02-15',N'25/3 Lạc Long Quân, Q.10, TP HCM',NULL,NULL),
							('002',N'Trần Trà Hương',2500.0,N'Nữ','1960-06-10',N'125 Trần Hưng Đạo, Q.1, TP HCM',NULL,NULL),
							('003',N'Nguyễn Ngọc Ánh',2200.0,N'Nữ','1975-05-11',N'12/21 Võ Văn Ngân, Thủ Đức, TP HCM','002',NULL),
							('004',N'Trương Nam Sơn',2300.0,'Nam','1959-06-20',N'215 Lý Thường Kiệt, TP Biên Hòa',NULL,NULL),
							('005',N'Lý Hoàng Hà',2500.0,'Nam','1954-10-23',N'22/5 Nguyễn Xí, Q.Bình Thạnh, TP HCM',NULL,NULL),
							('006',N'Trần Bạch Tuyết',1500.0,N'Nữ','1980-05-20',N'127 Hùng Vương, TP Mỹ Tho','004',NULL),
							('007',N'Nguyễn An Trung',2100.0,'Nam','1976-06-20',N'234 3/2, TP Biên Hòa',NULL,NULL),
							('008',N'Trần Trung Hiều',1800.0,'Nam','1977-06-05',N'22/11 Lý Thường Kiệt, TP Mỹ Tho','007',NULL),
							('009',N'Trần Hoàng Nam',2000.0,'Nam','1975-11-22',N'234 Trấn Não, An Phú, TP HCM','001',NULL),
							('010',N'Phạm Nam Thanh',1500.0,'Nam','1980-12-20',N'221 Hùng Vương, Q.5, TP HCM','007',NULL)


INSERT INTO KHOA VALUES ('CNTT',N'Công nghệ thông tin',1995,'B11','0838123456','002','2005-02-20'),
						('HH',N'Hóa Học',1980,'B41','0838456456','007','2001-10-15'),
						('SH',N'Sinh Học',1980,'B31','0838454545','004','2000-10-11'),
						('VL',N'Vật Lý',1976,'B21','0838223223','005','2003-09-18')

INSERT INTO BOMON VALUES ('CNTT',N'Công nghệ tri thức','B15','0838126126',NULL,'CNTT',NULL),
						 ('HHC',N'Hóa hữu cơ','B44','838222222',NULL,'HH',NULL),
						 ('HL',N'Hóa lý','B42','0838878787',NULL,'HH',NULL),
						 ('HPT',N'Hóa phân tích','B43','0838777777','007','HH','2007-10-15'),
						 ('HTTT',N'Hệ thống thông tin','B13','0838125125','002','CNTT','2004-09-20'),
						 ('MMT',N'Mạng máy tính','B16','0838676767','001','CNTT','2005-05-15'),
						 ('SH',N'Sinh hóa','B33','0838898989',NULL,'SH',NULL),
						 (N'VLĐT',N'Vật lý điện tử','B23','0838234234',NULL,'VL',NULL),
						 (N'VLƯD',N'Vật lý ứng dụng','B24','0838454545','005','VL','2006-02-18'),
						 ('VS',N'Vi sinh','B32','0838909090','004','SH','2007-01-01')

INSERT INTO CHUDE VALUES ('NCPT',N'Nghiên cứu phát triển'),
						 ('QLGD',N'Quản  lý giáo dục'),
						 (N'ƯDCN',N'Ứng dụng công nghệ')

INSERT INTO DETAI VALUES ('001',N'HTTT quản lý các trường ĐH','ĐHQG',20,'2007-10-20','2008-10-20','QLGD','002'),
						 ('002',N'HTTT quản lý giáo vụ cho một khoa',N'Trường',20,'2000-10-12','2001-10-12','QLGD','002'),
						 ('003',N'Nghiên cứu chế tạo sợi Nanô Platin','ĐHQG',300,'2008-05-15','2010-05-15','NCPT','005'),
						 ('004',N'Tại vật liệu sinh học bằng màng ối người',N'Nhà nước',100,'2007-01-01','2009-12-21','NCPT','004'),
						 ('005',N'Ứng dụng hóa học xanh',N'Trường',200,'2003-10-10','2004-12-10',N'ƯDCN','007'),
						 ('006',N'Nghiên cứu tế bào gốc',N'Nhà nước',4000,'2006-10-20','2009-10-20','NCPT','004'),
						 ('007',N'HTTT quản lý thư viện ở các trường ĐH',N'Trường',20,'2009-05-10','2010-05-10','QLGD','001')


INSERT INTO NGUOITHAN VALUES ('001',N'Hùng','1990-01-14','Nam'),
							 ('001',N'Thùy','1994-12-08',N'Nữ'),
							 ('003',N'Hà','1998-12-08',N'Nữ'),
							 ('003',N'Thu','1998-09-03',N'Nữ'),
							 ('007',N'Mai','2003-03-26',N'Nữ'),
							 ('007',N'Vy','2000-02-14',N'Nữ'),
							 ('008',N'Nam','1991-05-06','Nam'),
							 ('009',N'An','1996-08-19','Nam'),
							 ('010',N'Nguyệt','2006-01-14',N'Nữ')

INSERT INTO CONGVIEC VALUES ('001',1,N'Khởi tạo và Lập kế hoạch','2007-10-20','2008-12-20'),
							('001',2,N'Xác định yêu cầu','2008-12-21','2008-03-20'),
							('001',3,N'Phân tích hệ thống','2008-03-22','2008-06-22'),
							('001',4,N'Thiết kế hệ thống','2008-05-23','2008-06-23'),
							('001',5,N'Cài đặt thử nghiệm','2008-06-24','2008-10-20'),
							('002',1,N'Khỏi tạo và Lập kế hoạch','2009-05-10','2009-07-10'),
							('002',2,N'Xác định yêu cầu','2009-07-11','2009-10-11'),
							('002',3,N'Phân tích hệ thống','2009-10-12','2009-12-20'),
							('002',4,N'Thiết kế hệ thống','2009-12-31','2010-03-22'),
							('002',5,N'Cài đặt thử nghiệm','2010-03-23','2010-05-10'),
							('006',1,N'Lấy mẫu','2006-10-20','2007-02-20'),
							('006',2,N'Nuôi cấy','2007-02-21','2008-08-21')

INSERT INTO THAMGIADT VALUES ('001','002',1,0.0,NULL),
							 ('001','002',2,2.0,NULL),
							 ('002','001',4,2.0,N'Đạt'),
							 ('003','001',1,1.0,N'Đạt'),
							 ('003','001',2,0.0,N'Đạt'),
							 ('003','001',4,1.0,N'Đạt'),
							 ('003','002',2,0.0,NULL),
							 ('004','006',1,0.0,N'Đạt'),
							 ('004','006',2,1.0,N'Đạt'),
							 ('006','006',2,1.5,N'Đạt'),
							 ('009','002',3,0.5,NULL),
							 ('009','002',4,1.5,NULL)



INSERT INTO GV_DT VALUES ('001','0838912112'),
						 ('001','0903123123'),
						 ('002','0913454545'),
						 ('003','0838121212'),
						 ('003','0903656565'),
						 ('003','0937125125'),
						 ('006','0937888888'),
						 ('008','0653717171'),
						 ('008','0913232323')

UPDATE GIAOVIEN SET MABM = 'MMT' WHERE MAGV = '001'
UPDATE GIAOVIEN SET MABM = 'HTTT' WHERE MAGV = '002'
UPDATE GIAOVIEN SET MABM = 'HTTT' WHERE MAGV = '003'
UPDATE GIAOVIEN SET MABM = 'VS' WHERE MAGV = '004'
UPDATE GIAOVIEN SET MABM = N'VLĐT' WHERE MAGV = '005'
UPDATE GIAOVIEN SET MABM = 'VS' WHERE MAGV = '006'
UPDATE GIAOVIEN SET MABM = 'HPT' WHERE MAGV = '007'
UPDATE GIAOVIEN SET MABM = 'HPT' WHERE MAGV = '008'
UPDATE GIAOVIEN SET MABM = 'MMT' WHERE MAGV = '009'
UPDATE GIAOVIEN SET MABM = 'HPT' WHERE MAGV = '010'

