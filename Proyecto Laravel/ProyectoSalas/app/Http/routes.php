<?php

/*
|--------------------------------------------------------------------------
| Application Routes
|--------------------------------------------------------------------------
|
| Here is where you can register all of the routes for an application.
| It's a breeze. Simply tell Laravel the URIs it should respond to
| and give it the controller to call when that URI is requested.

|
*/

Route::get('/', 'LoginController@index');

Route::get('home', 'HomeController@index');

Route::resource('Administrador', 'AdministradorController');	

Route::get('Alumno','AlumnoController@getIndex');

Route::get('Alumno/Horario','HorarioController@getHorario');

Route::get('Alumno/consultaAlumno','ConsultaController@getconsultaAlumno');


Route::get('Docente','DocenteController@getIndex');

Route::get('Docente/HorarioDocente','HorarioController@getHorarioDocente');

Route::get('Docente/consultaDocente','ConsultaController@getconsultaDocente');

Route::get('Encargado','EncargadoController@getIndex');


Route::controllers([
	'auth' => 'Auth\AuthController',
	'password' => 'Auth\PasswordController',
]);
