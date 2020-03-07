const request = async () => {
    const response = await fetch('https://reqres.in/api/users?page=${page}&per_page=${per_page}');
    const users = await response.json();
    console.log(users);
    $('table tbody').empty();
    for(const user of users.data){
        console.log(user)
        let id = user.id
        let first_name = user.first_name
        let last_name = user.last_name
        let email = user.email
        let avatar = user.avatar
        $('table tbody').append('\
        <tr>\
        <th scope="row">'+id+'</th>\
        <td>'+first_name+'</td>\
        <td>'+last_name+'</td>\
        <td>'+email+'</td>\
        <td>\
            <img src='+avatar+' alt='+email+' class="img-thumbnail">\
        </td>\
        </tr>');
    }
   
}

request();