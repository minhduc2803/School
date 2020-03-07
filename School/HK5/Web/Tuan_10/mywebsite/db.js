var mysql = require('mysql');
function createConnection(){
  return mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "minhduc2002",
    database : 'dlbh'
  });
  
};

exports.load = sql => {
  return new Promise((resole,reject) => {
    const con = createConnection();
    con.connect(err => {
      if(err){
        reject(err);
      }
    });
    con.query(sql, (error, results, fields) => {
      if(error){
        reject(error);
      }
      resole(results);
    });
    con.end();
  });
};