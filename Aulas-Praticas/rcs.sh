#!/bin/bash

# Verifica a existência do arquivo header RCS
if [ ! -f "aula0801.h,v" ]; then
  # Executa o comando ci -i para o arquivo header
  ci -i aula0801.h
  
  # Executa o comando co para o arquivo header com a descrição 'initial check in'
  co aula0801.h
else
  ci "$filename"
  co "$filename"
fi

# Loop de 1 a 9
for i in {1..9}
do
  filename="aula080${i}.c"
  rcsfile="${filename},v"
  
  # Verifica a existência do arquivo RCS
  if [ ! -f "$rcsfile" ]; then
    # Executa o comando ci -i nome_do_arquivo
    ci -i "$filename"
    
    # Executa o comando co nome_do_arquivo com a descrição 'initial check in'
    co "$filename"
  else
    ci "$filename"
    co "$filename"
  fi
done