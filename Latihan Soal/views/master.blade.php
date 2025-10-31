<!DOCTYPE html>
<html>
    <head>
        <title>@yield('title')</title>
        <link />
        @vite(['resources/sass/app.scss', 'resources/js/app.js'])
    </head>
    <body>

        <div class="container">
            <div class="row">
                <div class="col">
                
                </div>
                <div class="col-12">
                    <h1 class="display-1 text-center">INFORMASI PARIWISATA ONLINE</h1>
                    <hr/>
                    <a href="/home">Home</a> | <a href="/category">Category</a> | <a href="">About Us</a>

                    <p>
                        @yield('content')
                    </p>

                    <hr/>
                    <p class="text-center">
                        <small>Copyright &copy Informasi Pariwisata Online {{date('Y')}}</small>
                    </p>
                </div>
                <div class="col">
                
                </div>
            </div>
        </div>
        
    </body>
</html>