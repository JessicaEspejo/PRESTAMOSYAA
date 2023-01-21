
    document.getElementById('apiBTN').addEventListener('click', cargarRES);

    function cargarRES(event) {
        event.preventDefault()
        console.log('llegue hasta qui----');
        fetch('https://api.currencyfreaks.com/latest?apikey=81ab526f45924a19a485ff8ed1a9ff53', {
            method: 'GET',
          
        })
            .then(function (response) {
                console.log('response =', response);
                return response.json();
            })
            .then(function (data) {
                console.log('data = ', data.rates.COP);
                
                let html = `
                <h1> Dólar Compra / Venta:  </h1>
                 <h2 class="subtitle"> 
                     ${Number(data.rates.COP).toFixed(2)} 
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

