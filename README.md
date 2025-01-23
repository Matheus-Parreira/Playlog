# Playlog

O Playlog é um pequeno programa que fiz para montar uma lista de músicas, de forma que ela fosse automáticamente organizada por ordem alfabética a cada música nova adicionada.

## Como funciona

As músicas da lista ficam salvas no arquivo de texto [log](playlist/log.txt), na pasta playlist; cada música contém informações sobre título, artista, ano de lançamento e país, além da data e horário
na qual ela foi registrada, e um número de ID de acordo com sua posição.

Ao ser iniciado, o programa abre esse arquivo, carregando as informações sobre quaisquer músicas que já estiverem lá em um vetor; em seguida, ele exibe o menu inicial, no qual o usuário
tem a opção de visualizar a lista diretamente pela própria janela do terminal, ou adicionar uma música nova, informando os dados dela para serem adicionados ao vetor.

Assim que a música é adicionada, o vetor então é automáticamente reordenado para "encaixá-la", seguindo sempre a ordem alfabética de artista, e depois de título (para o caso de várias 
músicas de um mesmo artista).

## Mudanças e Atualizações

Criei esse programa por um interesse pessoal meu e para aprender mais sobre a linguagem C (em especial leitura e escrita de arquivos, e algoritmos de ordenação), e resolvi
publicá-lo aqui não apenas para divulgar minha criação, mas também porque outras pessoas poderiam se interessar por ele - seja o usando para seu fim original, ou então reaproveitando 
o código para listar e ordenar outros tipos de dados.

Por isso o publiquei sob uma [Licença BSD](LICENSE), para que qualquer um possa modificá-lo para seus próprios fins (desde que sigam as cláusulas presentes nela).

Além disso, essa versão poderá também ser atualizada com novas funções, como:
- A capacidade de criar e acessar múltiplas playlists;
- Um ID único para cada música, independentemente de sua posição atual;
- A possibilidade de ordenar as músicas de outras formas (como por data adicionada, ano ou país)

## E é isso.

Espero que gostem bastante!
