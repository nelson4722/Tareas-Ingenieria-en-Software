<?php namespace App\Http\Controllers;

use App\Http\Requests;
use App\Http\Controllers\Controller;

//use Illuminate\Http\Request;
use Request;

use Illuminate\Support\Facades\Session;
use App\User;



class AdministradorController extends Controller {


	protected $layout='layouts.master';

	/**
	 * Display a listing of the resource.
	 *
	 * @return Response
	 */




	public function index()
	{
		$campus = User::paginate();

		return view('Administrador/indexAdministrador',compact('campus'));
	}

	/**
	 * Show the form for creating a new resource.
	 *
	 * @return Response
	 */
	public function create()
	{
		return view('Administrador.create');
	}

	/**
	 * Store a newly created resource in storage.
	 *
	 * @return Response
	 */
	public function store()
	{
	
		$user = new User();
		$user->fill(Request::all());
		$user->save();

		Session::flash('message', $user->nombre.' fue creado');

		return redirect()->route('Administrador.index');
	}

	/**
	 * Display the specified resource.
	 *
	 * @param  int  $id
	 * @return Response
	 */
	public function show($id)
	{
		//
	}

	/**
	 * Show the form for editing the specified resource.
	 *
	 * @param  int  $id
	 * @return Response
	 */
	public function edit($id)
	{
	
		$campusEditable = User::findOrFail($id);

		return view('Administrador.edit', compact('campusEditable'));
	
	}

	/**
	 * Update the specified resource in storage.
	 *
	 * @param  int  $id
	 * @return Response
	 */
	public function update($id)
	{
		$campusEditable = User::findOrFail($id);

		$campusEditable->fill(Request::all());
		$campusEditable->save();
		
		return redirect()->route('Administrador.index');
	}

	/**
	 * Remove the specified resource from storage.
	 *
	 * @param  int  $id
	 * @return Response
	 */
	public function destroy($id)
	{
		$campusEditable = User::findOrFail($id);

		$campusEditable->delete();

		Session::flash('message', $campusEditable->nombre. ' fue eliminado');

		return redirect()->route('Administrador.index');
	}

}
