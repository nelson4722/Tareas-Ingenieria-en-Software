@extends('layouts/master')



@section('welcome')

Gestión de salas - UTEM


@stop


@section('sideBar')



<div class="panel panel-default" style="margin-top: 40px;">
                        <div class="panel-heading">
                            

                            <h2><i class="glyphicon glyphicon-pencil" aria-hidden="true"></i><b> Bienvenido Docente </b></h2> 

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
  <div class="panel heading"><h2>Consultar asignaciones de salas</h2></div>
  <div class="form-group">
    
    <table class="table">
    <b>Campus </b> 
    <select name="campus" class="form-control">
    <option value="0">Macul</option>
    <option value="1">FAE</option>
    <option value="2">390</option>
    <option value="3">18</option>
    
      </select>

    </table> 


        <table class="table">
      <b>Día </b> 
    <select name="dia" class="form-control">
    <option value="0">Lunes</option>
    <option value="1">Martes</option>
    <option value="2">Miércoles</option>
    <option value="3">Jueves</option>
    <option value="4">Viernes</option>
    <option value="5">Sábado</option>
      </select>
    
    </table> 


        <table class="table">
      <b>Período </b> 
    <select name="periodo" class="form-control">
    <option value="0">I</option>
    <option value="1">II</option>
    <option value="2">III</option>
    <option value="3">IV</option>
    <option value="4">V</option>
    <option value="5">VI</option>
    <option value="6">VII</option>
    <option value="7">VIII</option>
    <option value="8">IX</option>
      </select>
    
    </table> 

    <div align=center><button type="button" class="btn btn-default"><b>Consultar </b></button></div>


   
 
  </div>

                    
</div>
</div>
</div>

                    
</div>


      </div>
    </div>

@stop