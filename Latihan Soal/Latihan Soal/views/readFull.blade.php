@extends('master')
@section('title', 'Full Article')
@section('content')

    <h2>{{$title}}</h2>
    <p>author : {{$author}}</p>
    <p>{{$articleContent}}</p>
    
@endsection