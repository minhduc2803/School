const db = require('../utils/db');

module.exports = {
  AddTier1: async (newtier1) => {
      const sql = `DELIMITER $$
      DROP FUNCTION IF EXISTS AddTier1;
      CREATE FUNCTION AddTier1 (newtier1 nvarchar(100))
      RETURNS NVARCHAR(100) DETERMINISTIC
        BEGIN DECLARE RESULT NVARCHAR(100);
        SET RESULT = NULL;
      IF newtier1 in (SELECT CATNAME FROM TIER1) THEN BEGIN SET RESULT = N'Tên danh mục không được trùng với danh mục đã có!'; END;
      ELSE BEGIN insert into TIER1(CATNAME) values (newtier1); SET RESULT = 'Thêm danh mục thành công!'; END;
      END IF;
        RETURN RESULT;
      END;
      $$ DELIMITER ;
      select AddTier1(${newtier1});`;
      const result = await db.load(sql);
      return result;
  },

  AddTier2: async (newtier2) => {
    const sql = `DELIMITER $$
    DROP FUNCTION IF EXISTS AddTier2;
    CREATE FUNCTION AddTier2 (newtier2 nvarchar(100))
    RETURNS NVARCHAR(100) DETERMINISTIC
      BEGIN DECLARE RESULT NVARCHAR(100);
      SET RESULT = NULL;
    IF newtier2 in (SELECT CATNAME FROM TIER1) THEN BEGIN SET RESULT = N'Tên danh mục không được trùng với danh mục đã có!'; END;
    ELSE BEGIN insert into TIER2(CATNAME) values (newtier2); SET RESULT = 'Thêm danh mục thành công!'; END;
    END IF;
      RETURN RESULT;
    END;
    $$ DELIMITER ;
    select AddTier1(${newtier2})`;
    const result = await db.load(sql);
    return result;
},

DeleteTier1: async (deleteid1) => {
  const sql = `DELIMITER $$
  DROP FUNCTION IF EXISTS DeleteTier1;
  CREATE FUNCTION DeleteTier1 (deleteid int)
  RETURNS NVARCHAR(100) DETERMINISTIC
  BEGIN
    DECLARE RESULT NVARCHAR(100);
      SET RESULT = NULL;
      IF (SELECT COUNT(*) FROM PRODUCT AS P JOIN TIER2 AS T2 ON  T2.ID = P.CATID WHERE T2.TIERID = deleteid) > 0
      THEN BEGIN
      SET RESULT = N'Không được xóa danh mục đã có sản phẩm!';
      END;
      ELSE
      BEGIN
      DELETE FROM TIER1 WHERE ID = deleteid;
      DELETE FROM TIER2 WHERE TIERID = deleteid;
      SET RESULT = N'Xóa danh mục thành công!';
      END;
    END IF;
      RETURN RESULT;
  END; $$
  DELIMITER ;
  SELECT DeleteTier1(${deleteid1});`;
  const result = await db.load(sql);
  return result;
},

DeleteTier2: async (deleteid2) => {
  const sql = `DELIMITER $$
  DROP FUNCTION IF EXISTS DeleteTier2;
  CREATE FUNCTION DeleteTier2 (deleteid int)
  RETURNS NVARCHAR(100) DETERMINISTIC
  BEGIN
    DECLARE RESULT NVARCHAR(100);
      SET RESULT = NULL;
      IF (SELECT COUNT(*) FROM PRODUCT WHERE CATID = deleteid) > 0
      THEN BEGIN
      SET RESULT = N'Không được xóa danh mục đã có sản phẩm!';
      END;
      ELSE
      BEGIN
      DELETE FROM TIER2 WHERE ID = deleteid;
      SET RESULT = N'Xóa danh mục thành công!';
      END;
    END IF;
      RETURN RESULT;
  END; $$
  DELIMITER ;
  SELECT DeleteTier2(${deleteid2});`;
  const result = await db.load(sql);
  return result;
},

UpdateTier1: async (updateid1) => {
  const sql = `DELIMITER $$
  DROP FUNCTION IF EXISTS UpdateTier1;
  CREATE FUNCTION UpdateTier1 (updateid int, updatecatname nvarchar(100))
  RETURNS NVARCHAR(100) DETERMINISTIC
  BEGIN
    DECLARE RESULT NVARCHAR(100);
      SET RESULT = NULL;
      IF (SELECT COUNT(*) FROM TIER1 WHERE ID = updateid) = 0
      THEN BEGIN
      SET RESULT = N'Không tồn tại danh mục trên!';
      END;
      ELSE IF (SELECT COUNT(*) FROM TIER1 WHERE CATNAME = updatecatname) > 0
      THEN BEGIN
      SET RESULT = N'Tên danh mục đã tồn tại!';
      END;
      ELSE
      BEGIN
      UPDATE TIER1 SET CATNAME = updatecatname WHERE ID = updateid;
      SET RESULT = N'Cập nhật danh mục thành công!';
      END;
      END IF;
      END IF;
      RETURN RESULT;
  END; $$
  DELIMITER ;
  
  SELECT UpdateTier1(1, ${updateid1});`;
  const result = await db.load(sql);
  return result;
},

UpdateTier2: async (updateid2) => {
  const sql = `DELIMITER $$
  DROP FUNCTION IF EXISTS UpdateTier2;
  CREATE FUNCTION UpdateTier2 (updateid int, updatecatname nvarchar(100))
  RETURNS NVARCHAR(100) DETERMINISTIC
  BEGIN
    DECLARE RESULT NVARCHAR(100);
      SET RESULT = NULL;
      IF (SELECT COUNT(*) FROM TIER2 WHERE ID = updateid) = 0
      THEN BEGIN
      SET RESULT = N'Không tồn tại danh mục trên!';
      END;
      ELSE IF (SELECT COUNT(*) FROM TIER2 WHERE CATNAME = updatecatname) > 0
      THEN BEGIN
      SET RESULT = N'Tên danh mục đã tồn tại!';
      END;
      ELSE
      BEGIN
      UPDATE TIER2 SET CATNAME = updatecatname WHERE ID = updateid;
      SET RESULT = N'Cập nhật danh mục thành công!';
      END;
      END IF;
      END IF;
      RETURN RESULT;
  END; $$
  DELIMITER ;
  
  SELECT UpdateTier2(1, ${updateid2})`;
  const result = await db.load(sql);
  return result;
},

DeleteProduct: async (deleteid) => {
  const sql = `DELIMITER $$
  DROP FUNCTION IF EXISTS DeleteProduct;
  CREATE FUNCTION DeleteProduct (deleteid int)
  RETURNS NVARCHAR(100) DETERMINISTIC
  BEGIN
    DECLARE RESULT NVARCHAR(100);
      SET RESULT = NULL;
      IF (SELECT COUNT(*) FROM PRODUCT WHERE ID = deleteid) = 0
      THEN SET RESULT = N'Không tồn tại sản phẩm trên!';
    ELSE
      BEGIN
    UPDATE PRODUCT SET STATUS = 2 WHERE ID = deleteid;
      SET RESULT = N'Xóa sản phẩm thành công!';
      END;
      END IF;
      RETURN RESULT;
  END; $$
  DELIMITER ;
  
  SELECT DeleteProduct(${deleteid});`;
  const result = await db.load(sql);
  return result;
},

AddUser: async (username, password,email,phone,address, first, last) => {
  const sql = `DELIMITER $$
  DROP FUNCTION IF EXISTS AddUser;
  CREATE FUNCTION AddUser (nUSERNAME VARCHAR(30), nPASSWORD VARCHAR(30), nEMAIL VARCHAR(50), nPHONE VARCHAR(20),
   nADDRESS NVARCHAR(255), nFIRST NVARCHAR(255), nLAST NVARCHAR(255))
  RETURNS NVARCHAR(100) DETERMINISTIC
  BEGIN
    DECLARE RESULT NVARCHAR(100);
      SET RESULT = NULL;
      IF nUSERNAME in (SELECT USERNAME FROM USER) THEN
      BEGIN
      SET RESULT = N'Username đã tồn tại!';
      END;
      ELSE IF nEMAIL in (SELECT EMAIL FROM USER) THEN
      BEGIN
      SET RESULT = N'Email đã được đăng ký!';
      END;
      ELSE IF nPHONE in (SELECT PHONE FROM USER) THEN
      BEGIN
      SET RESULT = N'Số điện thoại đã được đăng ký!';
      END;
      ELSE
      BEGIN
  INSERT INTO USER(USERNAME,PASSWORD,EMAIL,PHONE,ADDRESS,TYPE,FIRST,LAST)
  VALUES (nUSERNAME, nPASSWORD, nEMAIL, nPHONE, nADDRESS, 0 , nFIRST, nLAST);
      SET RESULT = 'Đăng ký người dùng thành công!';
      END;
    END IF;
       END IF;
    END IF;
      RETURN RESULT;
  END; $$
  DELIMITER ;
  select AddUser(${username}, ${password}, ${email} , ${phone}, ${address}, ${first}, ${last});`;
  const result = await db.load(sql);
  return result;
},

DeleteUser: async (deleteid) => {
  const sql = `DELIMITER $$
  DROP FUNCTION IF EXISTS DeleteUser;
  CREATE FUNCTION DeleteUser (deleteid int)
  RETURNS NVARCHAR(100) DETERMINISTIC
  BEGIN
    DECLARE RESULT NVARCHAR(100);
      SET RESULT = NULL;
      IF (SELECT COUNT(*) FROM dUSER WHERE ID = deleteid) = 0
      THEN BEGIN
      SET RESULT = N'Không tồn tại người dùng trên!';
      END;
      ELSE
      BEGIN
      UPDATE dUSER SET TYPE = -1 WHERE ID = deleteid;
      SET RESULT = N'Xóa thành công!';
      END;
      END IF;
      RETURN RESULT;
  END; $$
  SELECT DeleteUser(${deleteid})`;
  const result = await db.load(sql);
  return result;
},

Function: async () => {
  const sql = ``;
  const result = await db.load(sql);
  return result;
}

};
