const url = 'http://www.omdbapi.com/?i=tt3896198&apikey=c1d982c4';

fetch(url)
    .then(res => res.json())
    .then(movie => {
        var html;

        console.log(movie)

        html = `
        <div> 
             <img src="${movie.Poster}" class="image">
             <div> 
                <ul>
                <br><hr><br>
                  <li> <b>Film Adı: </b>${movie.Title}</li>
                  <li> <b>Yayınlanma Tarihi:  </b>${movie.Released}</li>
                  <li> <b>Film Süresi:  </b>${movie.Runtime}</li>
                  <li> <b>Oyuncular:  </b>${movie.Actors }</li>
                  <li> <b>Ödüller:  </b>${movie.Awards}</li>
                  <li> <b>Gişe Hasılatı: </b>${movie.BoxOffice}</li>
                  <li> <b>Ülke:  </b>${movie.Country}</li>
                  <li> <b>DVD:  </b>${movie.DVD}</li>
                  <li> <b>Tür:  </b>${movie.Genre}</li>
                  <li> <b>Dil:  </b>${movie.Language}</li>
                  <li> <b>Yönetmen:  </b>${movie.Director}</li>
                  <li> <b>Prodüksiyon:  </b>${movie.Production}</li>
                  <li> <b>Yazar:  </b>${movie.Writer}</li>
                  <li> <b>IMDB:  </b>${movie.imdbRating}</li>
                </ul>
             </div>            
        </div>        
        `
        document.querySelector("#output").innerHTML = html;
    })
    .catch(error => console.log("ERROR"))