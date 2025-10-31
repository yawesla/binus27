@extends('master')
@section('title', 'Home')
@section('content')

    <h2>Wisata Indonesia</h2>
    <p>Web Informasi Pariwisata Online adalah sebuah....</p>
    <h2>Article List</h2>
    @forelse ($articles as $article)
        <h3>{{$article->title}}</h3>
        <p>{{$article->author->name}}</p>
        <p><img src="{{asset('img/pemandangan.jpg')}}" width="75" height="75" /></p>
        <p>{{Str::limit($article->articleContent, 25)}} <a href="/readFull/{{$article->id}}"> read full article</a></p>
    @empty
        <b>No Article Found</b>
    @endforelse

    <p>{{$articles->links()}}</p>

@endsection