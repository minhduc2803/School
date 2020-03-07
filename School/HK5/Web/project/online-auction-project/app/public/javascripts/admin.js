function loginAd() {
    const username = $('#username').val();
    if (!username) {
        alert('Username empty!');
        return;
    }

    const password = $('#password').val();
    if (!password) {
        alert('Password empty!');
        return;
    }

    const form = document.createElement('form');
    form.method = 'POST';
    form.action = '/admin/login';

    const hidden1 = document.createElement('input');
    hidden1.type = 'hidden';
    hidden1.name = 'username';
    hidden1.value = username;
    const hidden2 = document.createElement('input');
    hidden2.type = 'hidden';
    hidden2.name = 'password';
    hidden2.value = password;

    form.appendChild(hidden1);
    form.appendChild(hidden2);

    document.body.appendChild(form);
    form.submit();
}

function mote(id,type){
    const form = document.createElement('form');
    form.method = 'POST';
    form.action = '/admin/user/mote';

    const hidden1 = document.createElement('input');
    hidden1.type = 'hidden';
    hidden1.name = 'id';
    hidden1.value = id;
    const hidden2 = document.createElement('input');
    hidden2.type = 'hidden';
    hidden2.name = 'type';
    hidden2.value = type;

    form.appendChild(hidden1);
    form.appendChild(hidden2);

    document.body.appendChild(form);
    form.submit();
}
function addc(id_input){
    var name = document.getElementById(id_input).value;
    const form = document.createElement('form');
    form.method = 'POST';
    form.action = '/admin/product/addc';

    const hidden1 = document.createElement('input');
    hidden2.type = 'hidden';
    hidden2.name = 'name';
    hidden2.value = name;

    form.appendChild(hidden1);

    document.body.appendChild(form);
    form.submit();
}
function adds(){
    var cat = document.getElementById('cat_input').value;
    var sub = document.getElementById('sub_input').value;
    const form = document.createElement('form');
    form.method = 'POST';
    form.action = '/admin/product/adds';

    const hidden1 = document.createElement('input');
    hidden1.type = 'hidden';
    hidden1.name = 'sub';
    hidden1.value = sub;

    const hidden2 = document.createElement('input');
    hidden2.type = 'hidden';
    hidden2.name = 'cat';
    hidden2.value = cat;

    form.appendChild(hidden1);
    form.appendChild(hidden2);

    document.body.appendChild(form);
    form.submit();
}


function logout(){
    window.location.href = '/admin/logout';
}