<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;

class CategorySeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        //
        \DB::table('categories')->insert(['category' => 'Wisata Pantai']);
        \DB::table('categories')->insert(['category' => 'Wisata Gunung']);
        \DB::table('categories')->insert(['category' => 'Lintas Alam']);
        \DB::table('categories')->insert(['category' => 'Wisata Museum']);
    }
}
