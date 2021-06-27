Trabalho prático da disciplina de Algoritmos I

O trabalho proposto consistia em desenvolver um sistema computacional capaz de resolver o
problema da distribuição de vacinas a partir de um centro para postos de vacinação levando
em consideração o alcance propiciado dada a variação da temperatura, para obter quantos e
quais postos seriam alcançados, além de descobrir se em algum caminho da rota um posto
seria alcançado por mais de uma vez, o que geraria ineficiência.
Desse modo, a modelagem mais simples e adequada para a resolução foi por meio de um
grafo no qual se inseriu a princípio os centros de vacinação como sendo os primeiros vértices
e posteriormente os postos até o último vértice. Após estabelecidas as devidas ligações de
arestas entre os vértices, bastou realizar o caminhamento Depth-First Search (DFS), ou Busca
em Profundidade, realizando algumas alterações em seu funcionamento para fazer com que o
nível de profundidade com o qual o caminhamento pudesse ocorrer fosse limitado (por causa
da variação da temperatura), além do reconhecimento de ciclos no caminhamento, ou seja, a
identificação de que em um mesmo caminhamento de uma rota haveria a passagem por mais
de uma vez em um posto.