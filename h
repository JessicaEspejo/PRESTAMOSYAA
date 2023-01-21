
    document.getElementById('apiBTN').addEventListener('click', cargarRES);

    function cargarRES(event) {
        event.preventDefault()
        console.log('llegue hasta qui----');
        fetch('https://api.apilayer.com/currency_data/convert?base=USD&symbols=EUR,GBP,JPY&amount=5&date=2023-01-15', {
            method: 'GET',
            headers: {
                'apikey': 'xikpRY77P7upPgO7vNdS0fynJxOpNJYK'
            },
        })
            .then(function (response) {
                console.log('response =', response);
                return response.json();
            })
            .then(function (data) {
                console.log('data = ', data);

                let html = `
                <h1> Dólar Compra / Venta:  </h1>
                 <h2 class="subtitle"> 
                    ${data}  
                </h2>
                <br></br>
                <h6> ¿Necesitas saber otras cotizaciones?<a href="https://www.dolarsi.com/"  target="_blank" class="subtitle"> 
                     Hace click acá.
                </a></h6>  
                `

                document.getElementById('Resulta').innerHTML = html;
            })
            .catch(function (err) {
               console.log('error de api',err);
            });

    }