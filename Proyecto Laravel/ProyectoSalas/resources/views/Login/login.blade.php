<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
    <meta name="description" content="">
    <meta name="author" content="">
    <link rel="icon" href="../../favicon.ico">

    <title>Sistema de Salas :: Universidad Tecnológica Metropolitana</title>

    <!-- Bootstrap core CSS -->
    <link href="css/bootstrap.css" rel="stylesheet">

    <!-- Custom styles for this template -->
    <link href="{{ asset('css/admin.css') }}" rel="stylesheet">


    <script src="../../assets/js/ie-emulation-modes-warning.js"></script>

    
  </head>

  <body>


<table align="center" width="650" border="0" height="50" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
            <tr>
                <td width="247" height="200"></td>
                <td width="225" height="200"><img src="images/esfera.jpg" width="225" height="200"></td>
                <td width="248" height="200"></td>
            </tr>
        </table>




    
<div id="wrapper">
      <div class="container" style="width: 350px;">
        <div class="panel panel-default" style="margin-top: 100px;">
        <div class="panel-heading">
        <form class="form-signin" method="post" action="/">

        <h2 class="form-signin-heading"><div align=center>Inicio de Sesión</div></h2>
        

         <form class="Inicio de sesion">
        <label for="rut" class="sr-only">Rut</label>
        <input type="rut" id="rut" class="form-control" placeholder="Rut" required autofocus>
        <label for="inputPassword" class="sr-only">Contraseña</label>
        <input type="password" id="inputPassword" class="form-control" placeholder="Contraseña" required>
        <div class="checkbox">
          <label>
            <input type="checkbox" value="recordarme"> Recordame
          </label>
        </div>
        <button class="btn btn-lg btn-primary btn-block" type="submit">Iniciar Sesión</button>
      </form>

    </div> <!-- /container -->


</div>


  <div class="container" style="margin-top: 120px;">
        <footer>© Sistema de salas UTEM - 2015</footer>
      </div>
  </body>
</html>
