<?php
        // Gabriel de Moura Schramm - Estrutura de Dados 2021/1 - Professor Ântonio Leães

print_r("Declaração da lista Legumes:\n");
$legumes=array('Arroz','Orégano','Batata','Lentilha','Milho');
print_r($legumes);

print_r("Adicionar um novo elemento no final da lista\n");
array_push($legumes, 'Feijão');
print_r($legumes);

print_r("Adicionar um novo elemento no inicio da lista\n");
array_unshift($legumes, 'Pimenta');
print_r($legumes);

print_r("Ordenação de elementos de forma descrescente\n");
rsort($legumes); 
print_r($legumes);

print_r("Remover o primeiro elemento da lista\n");
array_shift($legumes);
print_r($legumes);

print_r("Remover o ultimo elemento da lista\n");
array_pop($legumes);
print_r($legumes);

print_r("Ordenação de elementos de forma crescente\n");
sort($legumes);
print_r($legumes);

system('cls');
?>