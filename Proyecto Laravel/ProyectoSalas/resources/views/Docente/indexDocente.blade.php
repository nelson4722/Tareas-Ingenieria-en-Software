@extends('layouts/master')

@section('welcome')

Gestión de salas - UTEM


@stop


@section('sideBar')



<div class="panel panel-default" style="margin-top: 40px;">
                        <div class="panel-heading">
                            

                            <h2><i class="glyphicon glyphicon-lock" aria-hidden="true"></i><b> Bienvenido Docente </b></h2> 

                        </div>
                        <div class="panel-body">                  
                  
                        <div class="row">
                          <div class="col-sm-3">
                                          
                <div class="sidebar-nav navbar-collapse">
                    <ul class="nav" id="side-menu">
                    
                        <li>
                       <a class="list-group-item active"><i class="glyphicon glyphicon-list" aria-hidden="true"></i> Menú Docente</a>
</li>
            <li> <a href="{{URL::to('/Docente/HorarioDocente')}}">Horario</a></li>
            <li><a href="{{URL::to('/Docente/consultaDocente')}}">Consultar</a></li>            

</li>

</div>

</div>


         <div class="col-sm-9">
   <p>                                                    
                        </p>
                        <div class="bs-docs-section">                
<div class="panel panel-default">
<div class="panel-body">
  <div class="form-group">
  <div class="jumbotron">
      <h2>Aca va el horario con las salas y weas</h2>
      <p>XDDDDD</p>
     
    </div>
  </div>

                    
</div>
</div>
</div>

                    
</div>


      </div>
    </div>

@stop