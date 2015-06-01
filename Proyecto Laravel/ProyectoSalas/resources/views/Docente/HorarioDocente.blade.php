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
	 <div class="bs-docs-section">                
	 	
	 
	 		<div class="panel heading"><h2>Horario de clases</h2></div>
	 	
	 	<table id="sample-table-1" class="table table-striped table-bordered table-hover">
                       
                            <thead>
                                <tr>
                                    <th class="center" width="150px"><div align=center>Periodo</div></th>
                                    <th class="center" width="150px"><div align=center>Lunes</div></th>
                                    <th class="center" width="150px"><div align=center>Martes</div></th>
                                    <th class="center" width="150px"><div align=center>Miércoles</div></th>
                                    <th class="center" width="150px"><div align=center>Jueves</div></th>
                                    <th class="center" width="150px"><div align=center>Viernes</div></th>
                                    <th class="center" width="150px"><div align=center>Sábado</div></th>
                                </tr>
                            </thead>
                            <tbody>
                                                                <tr class="programa">
                                    <td align="center">I 08:00 - 09:30</td>
                                          <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                                                                        <tr class="programa">
                                            <td align="center">II 09:40 - 11:10</td>
                                           <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td> 
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                                                                        <tr class="programa">
                                           <td align="center">III 11:20 - 12:50</td>
                                          <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                                                                        <tr class="programa">
                                        <td align="center">IV 13:00 - 14:30</td>
                                         <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
                                                                                        <tr class="programa">
                                          <td align="center">V 14:40 - 16:10</td>
                                          <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                                                                        <tr class="programa">
                                          <td align="center">VI 16:20 - 17:50</td>
                                          <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                                                                        <tr class="programa">
                                            <td align="center">VII 18:00 - 19:30</td>
                                           <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td> 
                                                                                        <tr class="programa">
                                           <td align="center">VIII 19:00 - 20:30</td>
                                           <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                        												 <tr class="programa">
                                           <td align="center">IX 20:40 - 22:10</td>
                                           <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                          <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                           <td class="td" align="center" >  </td>
                                                                                    </tr>
                            </tbody>
                        </table>    


      </div>
    </div>

@stop

	