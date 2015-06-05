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
   <p> <h2>Lista de campus</h2></p>

      @if(Session::has('message'))

          <p class="alert alert-sucess"><b>{{ Session::get('message') }}</b></p>


      @endif
<div class="bs-docs-section">                
 <div class="panel panel-default">
   <div class="panel-body">
       <div class="form-group">

          <table class="table table-striped">
            <tr> 
              <th>#</th>
              <th>Campus</th>
              <th>Dirección</th>
              <th>Acciones</th>
            </tr>

            @foreach($campus as $campu)

            <tr>
               <td>{{ $campu->id}}</td>
               <td>{{ $campu->nombre}}</td>
               <td>{{ $campu->direccion}}</td>
               <td>
                  <a href="{{ route('Administrador.edit', $campu)}}">Editar</a>
                  <a href="{{ route('Administrador.edit', $campu) }}">Eliminar</a>
               </td>
            </tr>
             @endforeach

          </table>
          {!! $campus->render() !!}
     
  </div>

                    
</div>
</div>
</div>

                    
</div>


      </div>
    </div>


@stop