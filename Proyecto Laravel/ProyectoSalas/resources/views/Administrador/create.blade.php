@extends('layouts/master')

@section('welcome')

 Gestión de salas - UTEM


@stop


@section('sideBar')



<div class="panel panel-default" style="margin-top: 40px;">
                        <div class="panel-heading">
                            

                            <h2><i class="glyphicon glyphicon-user" aria-hidden="true"></i><b> Bienvenido Administrador </b></h2> 

                        </div>
                        <div class="panel-body">                  
                  
                        <div class="row">
                          <div class="col-sm-3">
                                          
                <div class="sidebar-nav navbar-collapse">
                    <ul class="nav" id="side-menu">
                    
                        <li>
                      <a class="list-group-item active"><i class="glyphicon glyphicon-list" aria-hidden="true"></i> Menú Administrador</a>
</li>
            <li> <a href="{{ route('Administrador.create') }}">Crear Campus</a></li>
            <li><a href="{{ route('Administrador.index') }}">Modificar Campus</a></li>
            <li><a href="">Archivar Campus</a></li>
            <li><a href="">Asignar Perfil</a></li>               

       
</li>

</div>

</div>



         <div class="col-sm-9" >
   <p> <h2>Ingrese los datos para crear un campus</h2></p>
<div class="bs-docs-section">                
 <div class="panel panel-default">
   <div class="panel-body">
       <div class="form-group">
  
      {!! Form::open(['route' => 'Administrador.store', 'method' => 'POST']) !!}

      <div class="form-group">
       {!! Form::label('nombre', 'Nombre') !!}
       {!! Form::text('nombre', '',['class' => 'form-control', 'placeholder' => 'Ingresa nombre']) !!}
         
      </div>

      <div class="form-group">
        {!! Form::label('direccion', 'Dirección') !!}
       {!! Form::text('direccion', '',['class' => 'form-control', 'placeholder' => 'Ingresa dirección']) !!}
      </div>

      <div class="form-group">
        {!! Form::label('latitud', 'Latitud') !!}
       {!! Form::text('latitud', '',['class' => 'form-control', 'placeholder' => 'Ingresa latitud']) !!}
      </div>

      <div class="form-group">
        {!! Form::label('longitud', 'Longitud') !!}
       {!! Form::text('longitud', '',['class' => 'form-control', 'placeholder' => 'Ingresa longitud']) !!}
      </div>

      <div class="form-group">
        {!! Form::label('descripcion', 'Descripción') !!}
       {!! Form::text('descripcion', '',['class' => 'form-control', 'placeholder' => 'Ingresa descripción']) !!}
      </div>

      <div class="form-group">
        {!! Form::label('rut_encargado', 'Rut Encargado') !!}
       {!! Form::text('rut_encargado', '',['class' => 'form-control', 'placeholder' => 'Ingresa rut']) !!}
      </div>

      <div align=center><button type="submit" class="btn btn-info">Crear campus</button></div>

      {!! Form::close() !!}
     
  </div>

                    
</div>
</div>
</div>

                    
</div>


      </div>
    </div>

@stop