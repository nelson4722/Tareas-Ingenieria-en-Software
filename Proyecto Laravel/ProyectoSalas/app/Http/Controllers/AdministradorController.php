<?php namespace App\Http\Controllers;




class AdministradorController extends Controller {


	protected $layout='layouts.master';

	public function getIndex()
	{

		return view('Administrador/indexAdministrador');

	}

}
