@extends('master')
@section('title', 'Article Category')
@section('content')

    <h2>Article List</h2>
    @forelse ($articles as $article)
        <h3>{{$article->title}}</h3>
        <p>author : {{$article->author->name}}</p>
        <p>{{Str::limit($article->articleContent, 25)}} <a href="/readFull/{{$article->id}}"> read full article</a></p>
        <p>category : 
            @forelse ($article->categories as $cate)
                {{$cate->category}} &nbsp
            @empty
                <b>No Category</b>
            @endforelse
        </p>
    @empty
        <b>No Article Found</b>
    @endforelse

    <p>{{$articles->links()}}</p>

@endsection