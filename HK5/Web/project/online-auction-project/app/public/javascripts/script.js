function timeleft(id, time) {

    var countDownDate = new Date(time).getTime();

    var x = setInterval(function () {

        var now = new Date().getTime();

        var distance = countDownDate - now;

        var days = Math.floor(distance / (1000 * 60 * 60 * 24));
        var hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
        var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
        var seconds = Math.floor((distance % (1000 * 60)) / 1000);

        document.getElementById(id).innerHTML = "Expire in: " + days + "d " + hours + "h " +
            minutes + "m " + seconds + "s ";

        if (distance < 0) {
            clearInterval(x);
            document.getElementById(id).innerHTML = "EXPIRED";
        }
    }, 1000);
}

function newitem(time, N) {

    var start = new Date(time).getTime();
    var now = new Date().getTime();
    var minutes = Math.floor((now - start) / (1000 * 60));

    if (minutes < N) {

        document.write('<p class="btn btn-danger" style="position: absolute;">New</p>');
    }
}

function dayleft(id, time) {

    var end = new Date(time);
    var now = new Date().getTime();
    var distance = end.getTime() - now;
    var days = Math.floor(distance / (1000 * 60 * 60 * 24));

    if (days < 3) {

        timeleft(id, time);
        return;
    }

    var monthNames = [
        " Jan ", " Feb ", " Mar ",
        " Apr ", " May ", " Jun ", " Jul ",
        " Aug ", " Sep ", " Oct ",
        " Nov ", " Dec "
    ];

    var day = end.getDate();
    var month = monthNames[end.getMonth()];
    var year = end.getFullYear();

    document.write('Expire on: ' + day + 'th' + month + year);
}

function add(e, id) {

    $.post("/wl/add", {
        id: id
    }, (data) => {
        if (data) {
            e.innerHTML = 'remove';
            e.className = 'btn btn-danger float-right';
            e.setAttribute("onClick", `javascript: rm(this, ${id});`);

            $('#wls').append(`
            <div id="wl${id}" class="col-12">
                <a href="/pro/{{id}}" style="text-decoration: none;" class="text-dark">
                    <div class="card">
                        <div class="card-body">
                        <h5 class="card-title">${data.name}</h5>
                        </div>
                        <div id="wlt${id}" class="card-footer">
                            <script src="/javascripts/script.js"></script>
                            <script>timeleft('wlt${id}', '${data.end}');</script>
                        </div>
                    </div>
                </a>
                <button onclick="rmwl('ib${id}', ${id})" class="btn btn-danger float-right"
                    style="position: absolute; right: 20px; bottom: 7px;">remove</button>
            </div>
        `)
        }
    });
}

function rm(e, id) {

    $.post("/wl/rm", {
        id: id
    }, (data) => {
        if (data) {
            e.innerHTML = 'add';
            e.className = 'btn btn-success float-right';
            e.setAttribute("onClick", `javascript: add(this, ${id});`);
            $(`#wl${id}`).remove();
        }
    });
}

function rmwl(ib, id) {

    var e = document.getElementById(ib);
    if (!e)
        return;

    $.post("/wl/rm", {
        id: id
    }, (data) => {
        if (data) {
            e.innerHTML = 'add';
            e.className = 'btn btn-success float-right';
            e.setAttribute("onClick", `javascript: add(this, ${id});`);
            $(`#wl${id}`).remove();
        }
    });
}

function bidCK(item, cost, login) {

    cm('#bidModal');

    if (!login) {
        alert('You need login to bid!');
        return;
    }

    const bid = document.getElementById("bid").value;

    if (isNaN(bid))
        return;

    if (bid <= cost) {
        alert(`Price must high than ${cost}!`);
        return;
    }

    $.post("/bid", {
        id: item,
        bid: bid
    }, (data) => {

        if (data) {
            $('#rsModal').modal("show");
            $('#rsTitle').html(data.msg);
            if (data.id)
                $('#rsBody').html(`<a href="/verify?id=${data.id}">Click here to verify!</a>`);
            else
                $('#rsBody').hide();
        }
    });
}

function cm(id) {
    $(id).hide();
}

function cf(id) {
    $(id).show();
}

function sendOTP(id) {
    $.post("/otp", {
        id: id
    }, (data) => {
        if (data)
            alert(data);
    });
}

function addAcc() {
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

    const email = $('#email').val();
    if (!email) {
        alert('Email empty!');
        return;
    }

    const first = $('#first').val();
    if (!first) {
        alert('First empty!');
        return;
    }

    const last = $('#last').val();
    if (!last) {
        alert('Last empty!');
        return;
    }

    $.post('/register', {
        username: username,
        password: password,
        email: email,
        first: first,
        last: last
    }, (data) => {
        if (data) {
            $('#rsModal').modal("show");
            $('#rsTitle').html(data.msg);
            if (data.id)
                $('#rsBody').html(`<a href="/verify?id=${data.id}">Click here to verify!</a>`);
            else
                $('#rsBody').hide();
        }
    })
}

function checkOTP(id) {
    const otp = $('#otp').val();
    if (!otp) {
        alert('Code empty');
        return;
    }

    $.post('/verify', {
        id: id,
        otp: otp
    }, (data) => {
        if (data) {
            $('#rsModal').modal("show");
            $('#rsTitle').html(data);
            if (data == 'Verify success!')
                $('#rsBody').html(`<a href="/">Home</a>`);
            else
                $('#rsBody').hide();
        }
    })
}

function loginAcc() {
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
    form.action = '/login';

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

function editPass() {
    const password = $('#password').val();

    if (!password) {
        alert('Current password empty!');
        return;
    }

    const newpass = $('#newpass').val();

    if (!newpass) {
        alert('New password empty!');
        return;
    }

    $.post('/acc/password', {
        password: password,
        newpass: newpass
    }, (data) => {
        if (data) {
            $('#rsModal').modal("show");
            $('#rsTitle').html(data.msg);
            $('#rsBody').hide();
            if (data.k)
                $('#passModal').hide();
        }
    })
}

function editAcc() {
    const email = $('#email').val();

    if (!email) {
        alert('Email empty!');
        return;
    }

    const first = $('#first').val();

    if (!first) {
        alert('first empty!');
        return;
    }

    const last = $('#last').val();

    if (!last) {
        alert('last empty!');
        return;
    }

    $.post('/acc/edit', {
        email: email,
        first: first,
        last: last
    }, (data) => {
        if (data) {
            $('#rsModal').modal("show");
            $('#rsTitle').html(data.msg);
            if (data.id)
                $('#rsBody').html(`<a href="/verify?id=${data.id}">Click here to verify!</a>`);
            else
                $('#rsBody').hide();
        }
    })
}

function review(item, toUser, rate) {
    const text = $('#review').val();

    $.post('/acc/review', {
        item: item,
        toUser: toUser,
        rate: rate,
        text: text
    }, (data) => {
        if (data) {
            $('#rsModal').modal("show");
            $('#rsTitle').html(data);
        }
    })
}

function upgrade() {
    $.post('/acc/upgrade', {}, (data) => {
        if (data) {
            alert(data);
        }
    })
}

function refresh() {
    location.reload();
}