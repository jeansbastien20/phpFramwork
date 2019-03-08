<?php
class BD
{
    protected $pdo;
    function __construct()
    {
            $this->pdo = new PDO('sqlite:../app/models/bd.sqlite3');
    }
}
?>
