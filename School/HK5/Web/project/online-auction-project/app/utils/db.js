const mysql = require('mysql')

exports.load = (sql) => {
    return new Promise((resolve, reject) => {
        const con = mysql.createConnection({
            host: 'localhost',
            port: '3306',
            user: 'root',
            password: 'minhduc2002',
            database: 'adb'
        });

        con.connect((err) => {
            if (err) {
                console.log(err);
                return;
            }
        });

        con.query(sql, (error, results, fields) => {
            if (error)
                console.log(error);

            resolve(results);
        });

        con.end();
    });
};

exports.add = (table, data) => {
    return new Promise((resolve, reject) => {
        const con = mysql.createConnection({
            host: 'localhost',
            port: '3306',
            user: 'root',
            password: 'minhduc2002',
            database: 'adb'
        });

        con.connect((err) => {
            if (err) {
                console.log(err);
                return;
            }
        });

        con.query(`insert into ${table} set ?`, data, (error, results, fields) => {
            if (error)
                console.log(error);

            resolve(results);
        });

        con.end();
    });
};

exports.addsub = (sub, cat) => {
    return new Promise((resolve, reject) => {
        const con = mysql.createConnection({
            host: 'localhost',
            port: '3306',
            user: 'root',
            password: 'minhduc2002',
            database: 'adb'
        });

        con.connect((err) => {
            if (err) {
                console.log(err);
                return;
            }
        });

        con.query(`insert into category(sub,cat) values('${sub}','${cat}')`, (error, results, fields) => {
            if (error)
                console.log(error);

            resolve(results);
        });

        con.end();
    });
};

exports.mote = (id, type) => {
    return new Promise((resolve, reject) => {
        const con = mysql.createConnection({
            host: 'localhost',
            port: '3306',
            user: 'root',
            password: 'minhduc2002',
            database: 'adb'
        });

        con.connect((err) => {
            if (err) {
                console.log(err);
                return;
            }
        });
        if(type == 2) type = 0;
        else type = 2;
        var sql = `update user set type = ${type} where id = ${id}`
        con.query(sql, (error, results, fields) => {
            if (error)
                console.log(error);

            resolve(results);
        });

        con.end();
    });
};