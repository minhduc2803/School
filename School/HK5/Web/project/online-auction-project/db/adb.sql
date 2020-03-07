DROP DATABASE IF EXISTS `adb`;
CREATE DATABASE `adb`;
USE `adb`;

CREATE TABLE `admin` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(30) NOT NULL,
  `password` varchar(72) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `username_UNIQUE` (`username`),
  UNIQUE KEY `password_UNIQUE` (`password`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;






CREATE TABLE `bid` (
  `id` int(10) unsigned NOT NULL,
  `user` int(10) unsigned NOT NULL,
  `cost` decimal(15,3) NOT NULL,
  `allow` tinyint(3) unsigned zerofill DEFAULT NULL,
  `create` datetime DEFAULT NULL, -- time when the lastest bid happened
  PRIMARY KEY (`id`,`user`),
  KEY `fk_bid_user_idx` (`user`)
  
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;






CREATE TABLE `category` (
  `sub` varchar(30) NOT NULL,
  `cat` varchar(30) NOT NULL,
  PRIMARY KEY (`sub`),
  UNIQUE KEY `sub_UNIQUE` (`sub`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


 

CREATE TABLE `item` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `text` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci,
  `subcat` varchar(30) NOT NULL,
  `cost` decimal(15,3) DEFAULT '0.000' not null,
  `costjump` decimal(15,3) not null,
  `start` datetime NOT NULL,
  `end` datetime NOT NULL,
  `seller` int(10) unsigned NOT NULL,
  `cost2` decimal(15,3) DEFAULT '0.000',
  `auto` tinyint(4) DEFAULT '0',
  PRIMARY KEY (`id`,`seller`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `fk_item_user_idx` (`seller`),
  KEY `fk_item_cat_idx` (`subcat`),
  FULLTEXT KEY `fulltext_item` (`name`,`text`)
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;



CREATE TABLE `review` (
  `id` int(10) unsigned NOT NULL,
  `user` int(10) unsigned NOT NULL,
  `text` mediumtext NOT NULL,
  `rate` int(10) NOT NULL check(`rate` <= 10),
  `date` datetime NOT NULL,
  `toUser` int(10) unsigned NOT NULL,
  PRIMARY KEY (`toUser`,`id`,`user`),
  KEY `fk_review_item` (`id`),
  KEY `fk_review_userB_idx` (`toUser`),
  KEY `fk_review_user` (`user`)
  
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;




CREATE TABLE `user` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(30) NOT NULL,
  `password` varchar(72) NOT NULL,
  `email` varchar(255) NOT NULL,
  `type` int(11) DEFAULT '0',
  -- 0 bidder
  -- 1 đang đợi nâng cấp thành seller
  -- 2 seller
  `first` varchar(15) NOT NULL,
  `last` varchar(15) NOT NULL,
  `name` varchar(30) GENERATED ALWAYS AS (concat(`first`,_utf8mb4' ',`last`)) VIRTUAL,
  `create` datetime DEFAULT NULL,
  `otp` char(4) DEFAULT NULL,
  `verified` tinyint(4) DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `username_UNIQUE` (`username`),
  UNIQUE KEY `email_UNIQUE` (`email`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;



CREATE TABLE `watchlist` (
  `user` int(10) unsigned NOT NULL,
  `item` int(10) unsigned NOT NULL,
  PRIMARY KEY (`user`,`item`),
  KEY `fk_wl_item_idx` (`item`)
  
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

CREATE TABLE `won` (
  `id` int(10) unsigned NOT NULL,
  `user` int(10) unsigned NOT NULL,
  `date` datetime NOT NULL,
  PRIMARY KEY (`id`,`user`),
  KEY `fk_ship_buyer_idx` (`user`),
  KEY `fk_ship_item_idx` (`id`)
  
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


alter table `bid` add
CONSTRAINT `fk_bid_item` FOREIGN KEY (`id`) REFERENCES `item` (`id`) on delete cascade;
alter table `bid` add
  CONSTRAINT `fk_bid_user` FOREIGN KEY (`user`) REFERENCES `user` (`id`) on delete cascade;
alter table `item` add
   CONSTRAINT `fk_item_cat` FOREIGN KEY (`subcat`) REFERENCES `category` (`sub`) on delete cascade;
alter table `item` add
  CONSTRAINT `fk_item_user` FOREIGN KEY (`seller`) REFERENCES `user` (`id`) on delete cascade;
  alter table `review` add
  CONSTRAINT `fk_review_item` FOREIGN KEY (`id`) REFERENCES `item` (`id`) on delete cascade;
  alter table `review` add
  CONSTRAINT `fk_review_user` FOREIGN KEY (`user`) REFERENCES `user` (`id`) on delete cascade;
  alter table `review` add
  CONSTRAINT `fk_review_userB` FOREIGN KEY (`toUser`) REFERENCES `user` (`id`) on delete cascade;
alter table `watchlist` add
CONSTRAINT `fk_wl_item` FOREIGN KEY (`item`) REFERENCES `item` (`id`) on delete cascade;
alter table `watchlist` add
CONSTRAINT `fk_wl_user` FOREIGN KEY (`user`) REFERENCES `user` (`id`) on delete cascade;
alter table `won` add
CONSTRAINT `fk_won_item` FOREIGN KEY (`id`) REFERENCES `item` (`id`) on delete cascade;
alter table `won` add
CONSTRAINT `fk_won_user` FOREIGN KEY (`user`) REFERENCES `user` (`id`) on delete cascade;

INSERT INTO `admin` VALUES (1,'duy','$2a$10$OkNIaGiMVs.qn6pQVWwYUunDI1WF96nCetyhWhoHw.bxCRwXWdfSS'),
(2,'dung','$2a$10$qHvQhoNtv9V/iJ1XS2/C/e2HKYl0BtDrC0Jbvz0DkpsIJqQ6YZuz2'),
(3,'duc','$2a$10$UAcb.okuJ3B6XV4g5hDehui7f0CLfmn3TmUYRIZpPzBJxPUhBONdG'),
(4,'doan','$2a$10$88Th.c.G8Jvo3JTaT0Y0te86eONWgwsdkEywWXYLaRWHwDp8MeesO');

INSERT INTO `user` 
(`id`, `username`, `password`, `email`, `type`, `first`, `last`, `create`, `otp`, `verified`) 
VALUES -- pass = 1
(1,'hihi','$2a$10$.5WTFOCD3mnAv5j3xgGIeuJw6V8oyFFOs40VrD3CFzEtfDchLswRy','',0,'','',NULL,NULL,1),
(2,'123','$2a$10$eewYfidpzJCCFJbZqdROyefCbVBfxo/zvrd/wEtsHxHvn9uKTiS/W','123@gm',0,'','',NULL,NULL,1),
(3,'1','$2a$10$0BOCo8/RzBNTWROssU/0.eEo5ZGb8PaYBS5pKakjPYsb1X6ui9jXq','1@g',0,'','','2019-12-21 01:46:31',NULL,1),
(4,'abc','$2a$10$wX5MOtVldcbdj9jNfHdUDu.Y8bU4zQmUqmnALgQst35Vh/AVc0SK2','giangho12988@gmail.com',0,'1','1','2019-12-24 17:07:30','5043',1),
(5,'q','$2a$10$0BRrVqvaPJYYNjoJpYP3xOQ0L4wTJ2WbAGFAQejX.eLPxtp2fPglK','q@a',0,'q','q','2019-12-24 21:44:47','9743',1),
(6,'qwe','$2a$10$czSqqgqq8oxl2mR33rB2leSytWr6nQVhbx5Dqni1ZFVWUFGiG/R7W','dtd2606@gmail.com',0,'123','456','2019-12-27 17:39:42','9497',1),
(7,'zxc','$2a$10$2yU5plqaq/Tfrh419om1p.sstYDtxg.WOeFYK.UKEs8MAMW.PzeyW','asd@gmail.com',0,'a','b','2019-12-28 00:08:25',NULL,1),
(8,'dung1999','$10$LM0Q73gp7CuUQgOyUzr.FeCIhcssW7TQv/0vk4jH0C73smFdu3hEq','quocdung@gmail.com',2,'Dung','Pham',
'2020-01-02 20:01:00',NULL,1),
(9,'duc','$2a$10$m7o8uflalUAzowDMFFV3H.c3nzWTitUZYUODxklHVgcvh3lnJTtRa','duc@gmail.com',2,'Duc','Nguyen',
'2020-01-02 20:54:41',NULL,1);
INSERT INTO `category` VALUES 
('Laptop','Electronic'),
('Mobile phone','Electronic'),
('Couch','Furniture'),
('Table','Furniture'),
('Tablet','Electronic'),
('Science','Book'),
('History','Book'),
('Earrings','Jewelry');


INSERT INTO `item` (`id`,`name`,`text`,`subcat`,`cost`,`costjump`,`start`,`end`,`seller`,`cost2`,`auto`) VALUES 
(1,'Iphone 11','The newest model of Iphone with a reasonable price','Mobile phone',1000,50,
'2019-12-12 00:00:00','2020-01-20 00:00:00',8,1500,0),
(2,'Oppo F9','New model of Oppo','Mobile phone',500,50,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',8,800,0),
(3,'Ipad Air 3','A convenient tablet with a good price','Tablet',550,20,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',8,800,0),
(4,'Ipad Air 2','An old but useful tablet','Tablet',300,20,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',8,500,0),
(5,'Oppo F7',"A good phone, isn't used much",'Mobile phone',400,50,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',8,700,0),
(6,'A brief history of time','An incredible book written by Stephen Hawking','Science',50,5,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',8,80,0),
(7,'Pale Blue Dot: A Vision of the Human Future in Space','An inspirational boook by Carl Sagan','Science',50,5,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',8,80,0),
(8,'Luxury earrings','This earrings can make you look like a luxurious lady','Earrings',500,25,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',8,700,0),
(9,'Long drop earrings','The unique earrings','Earrings',100,10,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',8,200,0),
(10,'Iphone 7','Condition: 90%','Mobile phone',300,25,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',8,500,0),
(11,'Samsung Galaxy S10','Just buy some days ago. Need to sell','Mobile phone',900,25,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',9,1100,0),
(12,'Samsung Galaxy S8','A good yet useful phone','Mobile phone',450,50,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',9,700,0),
(13,'Brown couch','Dimension: 2.5m x 0.5m x 1m','Couch',500,25,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',9,NULL,0),
(14,'Red couch','Dimension: 2.5m x 0.5m x 1m','Couch',300,30,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',9,600,0),
(15,'Dining table','Dimension: 4m x 1m x 1.1m','Table',500,20,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',9,700,0),
(16,'Black table','Dimension: 1.3m x 0.5m x 0.9m','Table',100,10,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',9,200,0),
(17,'Founding Brothers: The Revolutionary Generation','An amazing book about the history of US in 1790s',
'History',100,10,'2019-12-12 00:00:00','2020-01-20 00:00:00',9,200,0),
(18,'Sapiens: A Brief History Of Humankind','Contains a lot of info about the evolution of human',
'History',50,5,'2019-12-12 00:00:00','2020-01-20 00:00:00',9,80,0),
(19,'Dell Inspiron 5570','A powerful laptop','Laptop',1000,50,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',9,1300,0),
(20,'Asus Vivobook','A powerful laptop','Laptop',700,50,'2019-12-12 00:00:00',
'2020-01-20 00:00:00',9,1100,0);
 

INSERT INTO `bid` (`id`,`user`,`cost`,`allow`,`create`) VALUES 
(1,5,1000,001,'2019-12-22 11:10:01'),
(1,7,1100,001,'2019-12-24 08:00:00'),
(1,3,1150.000,000,'2019-12-25 00:03:00'),
(1,6,1200.000,001,'2019-12-26 07:00:00'),
(1,2,1300.000,001,'2019-12-27 02:00:00'),
(1,9,1400.000,001,'2019-12-28 12:00:00'),
(2,5,5000,001,'2019-12-22 11:10:01'),
(2,7,550,001,'2019-12-24 08:00:00'),
(2,3,600,000,'2019-12-25 00:03:00'),
(2,6,700,001,'2019-12-26 07:00:00'),
(2,1,750,001,'2019-12-27 02:00:00'),
(3,5,550,001,'2019-12-22 11:10:01'),
(3,7,590,001,'2019-12-24 08:00:00'),
(3,3,630,000,'2019-12-25 00:03:00'),
(3,6,670,001,'2019-12-26 07:00:00'),
(3,1,690,001,'2019-12-27 02:00:00'),
(4,5,300,001,'2019-12-22 11:10:01'),
(4,7,340,001,'2019-12-24 08:00:00'),
(4,3,420,000,'2019-12-25 00:03:00'),
(4,6,440,001,'2019-12-26 07:00:00'),
(4,1,460,001,'2019-12-27 02:00:00'),
(5,5,400,001,'2019-12-22 11:10:01'),
(5,7,450,001,'2019-12-24 08:00:00'),
(5,3,500,000,'2019-12-25 00:03:00'),
(5,6,550,001,'2019-12-26 07:00:00'),
(5,1,600,001,'2019-12-27 02:00:00'),
(6,5,50,001,'2019-12-22 11:10:01'),
(6,7,55,001,'2019-12-24 08:00:00'),
(6,3,60,000,'2019-12-25 00:03:00'),
(6,6,65,001,'2019-12-26 07:00:00'),
(6,1,70,001,'2019-12-27 02:00:00'),
(7,5,50,001,'2019-12-22 11:10:01'),
(7,7,60,001,'2019-12-24 08:00:00'),
(7,3,65,000,'2019-12-25 00:03:00'),
(7,6,70,001,'2019-12-26 07:00:00'),
(7,2,75,001,'2019-12-27 02:00:00'),
(8,5,500,001,'2019-12-22 11:10:01'),
(8,7,525,001,'2019-12-24 08:00:00'),
(8,3,550,000,'2019-12-25 00:03:00'),
(8,6,575,001,'2019-12-26 07:00:00'),
(8,1,600,001,'2019-12-27 02:00:00'),
(9,5,100,001,'2019-12-22 11:10:01'),
(9,7,110,001,'2019-12-24 08:00:00'),
(9,3,130,000,'2019-12-25 00:03:00'),
(9,6,160,001,'2019-12-26 07:00:00'),
(9,1,200,001,'2019-12-27 02:00:00'),
(10,5,300,001,'2019-12-22 11:10:01'),
(10,7,325,001,'2019-12-24 08:00:00'),
(10,3,350,000,'2019-12-25 00:03:00'),
(10,6,375,001,'2019-12-26 07:00:00'),
(10,1,400,001,'2019-12-27 02:00:00'),
(11,5,900,001,'2019-12-22 11:10:01'),
(11,7,925,001,'2019-12-24 08:00:00'),
(11,3,950,000,'2019-12-25 00:03:00'),
(11,6,975,001,'2019-12-26 07:00:00'),
(11,1,1000,001,'2019-12-27 02:00:00'),
(12,5,450,001,'2019-12-22 11:10:01'),
(12,7,500,001,'2019-12-24 08:00:00'),
(12,3,550,000,'2019-12-25 00:03:00'),
(12,6,600,001,'2019-12-26 07:00:00'),
(12,1,650,001,'2019-12-27 02:00:00'),
(13,5,500,001,'2019-12-22 11:10:01'),
(13,7,700,001,'2019-12-24 08:00:00'),
(13,3,725,000,'2019-12-25 00:03:00'),
(13,6,750,001,'2019-12-26 07:00:00'),
(13,1,900,001,'2019-12-27 02:00:00'),
(14,5,300,001,'2019-12-22 11:10:01'),
(14,7,330,001,'2019-12-24 08:00:00'),
(14,3,360,000,'2019-12-25 00:03:00'),
(14,6,390,001,'2019-12-26 07:00:00'),
(14,4,420,001,'2019-12-27 02:00:00'),
(15,5,500,001,'2019-12-22 11:10:01'),
(15,7,540,001,'2019-12-24 08:00:00'),
(15,3,560,000,'2019-12-25 00:03:00'),
(15,6,600,001,'2019-12-26 07:00:00'),
(15,1,660,001,'2019-12-27 02:00:00'),
(16,5,100,001,'2019-12-22 11:10:01'),
(16,7,110,001,'2019-12-24 08:00:00'),
(16,3,120,000,'2019-12-25 00:03:00'),
(16,6,140,001,'2019-12-26 07:00:00'),
(16,8,180,001,'2019-12-27 02:00:00'),
(17,5,100,001,'2019-12-22 11:10:01'),
(17,7,120,001,'2019-12-24 08:00:00'),
(17,3,150,000,'2019-12-25 00:03:00'),
(17,6,160,001,'2019-12-26 07:00:00'),
(17,1,170,001,'2019-12-27 02:00:00'),
(18,5,50,001,'2019-12-22 11:10:01'),
(18,7,60,001,'2019-12-24 08:00:00'),
(18,3,65,000,'2019-12-25 00:03:00'),
(18,6,70,001,'2019-12-26 07:00:00'),
(18,1,75,001,'2019-12-27 02:00:00'),
(19,5,1000,001,'2019-12-22 11:10:01'),
(19,7,1050,001,'2019-12-24 08:00:00'),
(19,3,1100,000,'2019-12-25 00:03:00'),
(19,6,1150,001,'2019-12-26 07:00:00'),
(19,1,1250,001,'2019-12-27 02:00:00'),
(20,5,700,001,'2019-12-22 11:10:01'),
(20,7,750,001,'2019-12-24 08:00:00'),
(20,3,850,000,'2019-12-25 00:03:00'),
(20,6,900,001,'2019-12-26 07:00:00'),
(20,8,1000,001,'2019-12-27 02:00:00');

INSERT INTO `review` VALUES (9,1,'I won this!',9.5,'2019-12-30 16:15:36',8);



INSERT INTO `watchlist` VALUES (5,1),(3,2),(4,3),(1,4);
INSERT INTO `won` VALUES (9,1,'2019-12-27 02:00:00');
