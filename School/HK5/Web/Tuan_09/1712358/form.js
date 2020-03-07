const express = require('express');
const app = express();

const port = 3000;

app.get('/',(req, res) => {
  res.redirect('/home.html');
});

app.get('/acknowledge.html',(req,res) => {
  let check = 'CHƯA';
  let begin = '';
 
  if(req.query.checkbox == 'on'){
    check = 'ĐÃ';
    begin = 'Chúc mừng ! ';

  }
  res.writeHead(200);
  res.write(`
  <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <style>
    main{
        display: block;
        width:25rem;
        margin: 0 auto;
        margin-top: 50px;
    }
    </style>
    
    <title>Home</title>
</head>
<body>
    <div class="cover-container d-flex h-100 p-3 mx-auto flex-column text-center">
        <main role="main" class="inner cover">
                <h1 class="cover-heading">Hội nghị đoàn viên</h1>
                <p class="lead">Xin chào ${req.query.hoten}</p>
                <p class="lead">Thông tin</p>
                <p class="lead">Email: ${req.query.email}</p>
                <p class="lead">Số điện thoại: ${req.query.sdt}</p>
                <p class="lead">${begin}Bạn ${check} xác nhận đăng ký tham gia hội nghị.</p>
                <p class="lead">
                    <a href="/home.html" class="btn btn-lg btn-secondary">Trang chủ</a>
                  <a href="/form.html" class="btn btn-lg btn-secondary">Trang đăng ký</a>
                 
                </p>
              </main></div>

              <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
              <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
              <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
</body>
</html>
  `);
  res.end();
});
app.use(express.static('view'));


app.listen(port,() => console.log(`Server is running on port ${port}`));