/*Melhorias futuras:
1- Criar a historia do inicio ao fim para ela ficar mais amarrada (talvez necessaria a reescrita doq ja foi feito).
2- Combate mais complexo e dinamico.
3- Aprimorar as outras opcoes alem do combate. 
4- melhorar loja: (nivel de itens limitado pra comprar)
5- adicionar um limite de vida (podendo ser upgradeada na loja (5x mais cara que uma pocao comum))
6- melhoria no inventario: (item realmente aparecer no inventario e nao apenas somar nos status)
7- novos atributos como inteligencia/percepcao
8- novas classes como Anão.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // funcao pra criar o randomizador (importante para o d20)
#include <unistd.h> // funcao pra deixar o texto lento (usleep())
int forca = 0;
int carisma = 0;
int vigor = 0;
int stealth = 0;
// int inteligencia = 0; (dps eu penso em adicionar)

int dado20() {
	 return(rand() % 20) + 1;
}

// Funcao para simular a digitacao do texto
void prints(const char *texto) {
	while (*texto) {
		putchar(*texto); // imprime um caractere
		fflush(stdout); // faz os caracteres irem um de cada vez
		usleep(15000); // velocidade dos caracteres
		texto++;
	}
// texto lento para ser mais tramatico
}
void printl(const char *texto) {
	while (*texto) {
		putchar(*texto); // imprime um caractere
		fflush(stdout); // faz os caracteres irem um de cada vez
		usleep(40000); // velocidade dos caracteres
		texto++;
	}

}
void esperarEnter() {
    
    while(getchar() != '\n'); // limpa o buffer, caso tenha lixo
    getchar(); // espera o Enter
}


void elion(int classe) {
	if(classe == 1) {
		printf("Guerreiro");
		forca = 5;
		vigor = -3;
		stealth = -3;
		carisma = 2;
	}
	if(classe == 2) {
		printf("Ladino");
		forca = -2;
		carisma = -4;
		vigor = 4;
		stealth = 4;
	}
	if(classe == 3) {
		printf("Bardo");
		forca = -4;
		carisma = 6;
		vigor = 2;
		stealth = -2;
	}
}

void bonus(int classe) {
	if(classe == 1) {
		forca = 5;
		vigor = -3;
		stealth = -3;
		carisma = 2;
			printf("Forca{f} %d / Vigor{v} %d / Stealth{s} %d / Carisma{c} %d\n", forca ,vigor ,stealth ,carisma);
	}
	if(classe == 2) {
		forca = -2;
		vigor = 4;
		stealth = 4;
		carisma = -4;
		printf("Forca{f} %d / Vigor{v} %d / Stealth{s} %d / Carisma{c} %d\n", forca ,vigor ,stealth ,carisma);
	}
	if(classe == 3) {
		forca = -4;
		vigor = 2;
		stealth = -2;
		carisma = 6;
		printf("Forca{f} %d / Vigor{v} %d / Stealth{s} %d / Carisma{c} %d\n", forca ,vigor ,stealth ,carisma);
	}
}

int verHP(int hp) { //para chamar funcao verHP(hp);
    printf("HP de Elion:%d❤️\n", hp);
    if (hp <= 0) {
        prints("\nVoce foi derrotado...\nGAME OVER\n");
        exit(0); // encerra o jogo se o HP for 0 ou menor
    }
}
int verHPI(int hpi) { //para chamar funcao verHPI(hpi);
	
    printf("HP do adversario:%d❤️\n", hpi);
    
}
int verDin(int din){ //para chamar funcao verDin(din);
    printf ("Dinheiro restante:%d Moedas\n", din);
}
int main() {
    int aposta = 0;// pro tigrinho
    int hp = 10;
    int hpi = 15;
    int din = 15;
	int sucesso = 0;
	int e1,e2,e3,classe;
	srand(time(NULL));

	prints("(Para Sim digite 1 e Nao 0)\n");
	prints("Voce e Elion, um heroico aprendiz que percorre uma terra cheia de perigos.\n");
	prints("Escolha sua Classe:\n");
	prints("(1) Guerreiro: / +5 Forca{f}  / -3 Vigor{v}  / -3 Stealth{s}  / +2 Carisma{c} \n");
	prints("(2) Ladino:   / -2 Forca{f}  / +4 Vigor{v}  / +4 Stealth{s}  / -4 Carisma{c}\n");
	prints("(3) Bardo:   / -4 Forca{f}  / +2 Vigor{v}  / -2 Stealth{s}  / +6 Carisma{c}\n");
	scanf("%d", &classe);
	system("clear");
	printf("Classe escolhida:");
	elion(classe);

	printf("\n");
	bonus(classe);

	int td = 0;
	int rolagem = dado20(); // DADO
	int totalf = forca + rolagem;
	int totalc = carisma + rolagem;
	int totalv = vigor + rolagem;
	int totals = stealth + rolagem;
//Capitulo 0 (TUTORIAL)

	prints("\nINICIO:\nNa saida do vilarejo, seu mestre  te encara com preocupacao.\n");
	prints("Splinter: Oh grande Elion, sua coragem e admiravel, mas creio que voce nao possui o que e necessario para continuar...\n\n");
	prints("Escolha sua acao:\n");
	prints("(1) E isso que vamos ver... (Desafiar Splinter) {F8}\n");
	prints("(2) Eu entendo sua preocupacao mas tenho coisas a fazer, Me deixe passar. (Tentar convencer) {C8}\n");
	prints("(3) Foda-se fui! (Sair correndo) {V7}\n\n");
	scanf("%d", &e1);

	do {
	    int rolagem = dado20(); // DADO
    int totalf = forca + rolagem;
    int totalc = carisma + rolagem;
    int totalv = vigor + rolagem;
    int totals = stealth + rolagem;
		switch(e1) {
		case 1:
			system("clear");
			bonus(classe);
			prints("\nVoce desafia o mestre Splinter! {Forca necessaria:8}\n");
			prints("Aperte enter para Rolar o Dado:");
			esperarEnter();
			printl("D20 de forca: ");
			usleep(700000); // pausa dramC!tica antes do nC:mero
			printf("%d!\n", rolagem);

			printl("Sua forca total: ");
			usleep(700000);
			printf("%d!\n", totalf);


			if(totalf<4) {
				prints("Com apenas 2 movimentos de seu mestre, voce esta no chao.\n");
				prints("Splinter: Achei que voce nao estava pronto, agora tenho certeza.\n");
				sucesso = 0;
			} else if (totalf>=4&& totalf<=7) {
				prints("Elion consegue manter a batalha por um tempo, mas ainda nao esta no nivel de seu mestre.\n");
				prints("Splinter: Voce e forte, mas nao o suficiente.\n");
				sucesso = 0;
			} else if (totalf>7 && totalf<11) {
				prints("Elion e Splinter travam uma batalha de igual pra igual, depois de quase 30 minutos, Splinter interrompe a batalha e diz:\n");
				prints("eu te ensinei bem, siga seu caminho sem olhar pra tras.\n");
				sucesso = 1;
			} else if (totalf>=11 && totalf<20) {
				prints("Elion e Splinter travam uma batalha epica, mas Elion necessitou apenas de uma abertura na guarda de Splinter para o derrubar.\n");
				prints("Splinter: eu estava enganado, voce se tornou um grande ");
				elion(classe);
				prints(".\n");
				sucesso = 1;
			}
			else if (totalf>=20) {
				prints("A batalha se decidiu em apenas 2 movimentos, Splinter nao teve a menor chance.\n");
				prints("Splinter: O quao forte voce se tornou jovem? em questao de poder bruto voce ja me ultrapassou... voce se tornou um grande ");
				elion(classe);
				prints(".\n");
				sucesso = 1;
			}
			break;
		case 2:
			system("clear");
			bonus(classe);
			prints("\nVoce tenta convencer o mestre! {Carisma necessario:8}\n");
			prints("Aperte enter para Rolar o Dado:");
			esperarEnter();
			printl("D20 de Carisma: ");
			usleep(700000); // pausa dramC!tica antes do nC:mero
			printf("%d!\n", rolagem);

			printl("Seu carisma total: ");
			usleep(700000);
			printf("%d!\n", totalc);

			if(totalc<4) {
				prints("Elion explica que precisa sair agora para nao voltar tao tarde.\n");
				prints("Splinter: Esse e o pior argumento que eu ja ouvi.\n");
				sucesso = 0;
			} else if (totalc>=4&& totalc<=7) {
				prints("Elion diz que precisa ir pro vale para ficar mais forte.\n");
				prints("Splinter: Eu entendo o seu ponto, mas voce nao vai continuar.\n");
				sucesso = 0;
			} else if (totalc>7 && totalc<11) {
				prints("Elion diz que esta pronto.\n");
				prints("Splinte: Compreensivel tenha um otimo dia\n");
				sucesso = 1;
			} else if (totalc>11) {
				prints("Elion diz que esta pronto e precisa dessa jornada para se tornar um grande ");
				elion(classe);
				prints(".\n");
				prints("Splinter: eu entendo sua situacao, siga seu caminho sem olhar pra tras.\n");
				sucesso = 1;
			}
			break;
		case 3:
			system("clear");
	    	bonus(classe);
			prints("\nVoce tenta fugir do mestre! {Vigor necessario:7}\n");
			prints("Aperte enter para Rolar o Dado:");
			esperarEnter();
			printl("D20 de Vigor: ");
			usleep(700000); // pausa dramatica antes do nC:mero
			printf("%d!\n", rolagem);

			printl("Seu vigor total: ");
			usleep(700000);
			printf("%d!\n", totalv);

			if(totalv<4) {
				prints("Elion da 3 passos antes de tropecar e cair de cara no chao.\n");
				prints("Splinter: e humilhande ter voce como pupilo.\n");
				sucesso = 0;
			} else if (totalv>=4&& totalv<=6) {
				prints("Elion quase consegue fugir porem, Splinter e mais rapido.\n");
				prints("Splinter: Nao te criei desde pequeno para voce me tratar assim...\n");
				sucesso = 0;
			} else if (totalv>6 && totalv<=11) {
				prints("Elion consegue escapar por pouco das maos de seu mestre.\n");
				prints("Splinter: Desgracado ligeiro, ESSE TRUQUE NAO VAI FUNCIONAR NA FLORESTA.\n");
				sucesso = 1;
			} else if (totalv>11&& totalv<18) {
				prints("devido a sua alta idade Splinter nao e capaz de te pegar.\n");
				prints("Splinter: droga de ernia de disco...\n");
				sucesso = 1;
			} else if (totalv>18) {
				prints("Splinter nao consegue nem te acompanhar com os olhos.\n");
				prints("Splinter: quando foi que voce ficou tao rapido?... voce se tornou um grande \n");
				elion(classe);
				prints(".");
				sucesso = 1;
			}
			break;
		default:
			prints("Opcao invalida.\n");
			break;
		}
		if (sucesso==1) {
			prints("\nElion sai de sua vila, determinado a conquistar as riquezas deste mundo.\n");
			prints("(Aperte enter para seguir)\n");
			esperarEnter();
			system("clear");
			

		}
		else {
			prints("\nTentar denovo?\n");
			scanf("%d",&td);
			if(td==1) {
				system("clear");
				prints("Elion:Nao vou desistir tao facil...\n Splinter: teimoso como sempre.\n");
				prints("Escolha sua acao:\n");
				prints("(1) voce me conhece... (Desafiar Splinter) {F8}\n");
				prints("(2) Se sou teimoso, e porque realmente preciso ir. (Tentar convencer) {C8}\n");
				prints("(3) Foda-se de novo! (Sair correndo mais uma vez..) {V7}\n");
				scanf("%d", &e1);
			} else {
				prints("GAME OVER");
				return 0;
				
			}
		}
	} while (sucesso == 0);
	/*
Capitulo 1: A vila dos Anões
hp e combate aprimorado

*/
    prints("Elion se encontra trilhando o caminho de sua jornada, porem, depois de uma longa caminhada pela floresta, ele encontra uma vila de Anões com um ser guardando sua entrada.\n\n");
    prints("Um ser de 2.5 metros com a pele esverdeada e um porrete na mao, O guardião da entrada da vila.\n O mesmo ordena Elion a dar meia volta antes que seja tarde. \n");
   	prints("Escolha sua acao:\n");
   	bonus(classe);
   	verHP(hp);
    prints("(1) Saia da minha frente se não voce sera um Goblin morto. (Desafiar Troll) {F13}\n");
	prints("(2) Meu caro amigo Troll, nao se lembra de mim?. (Tentar convencer) {C10}\n");
	prints("(3) Foda-se fui! (Sair correndo) {V9}\n\n");
		scanf("%d", &e1);
			do {
	    int rolagem = dado20(); // DADO
    int totalf = forca + rolagem;
    int totalc = carisma + rolagem;
    int totalv = vigor + rolagem;
    int totals = stealth + rolagem;
		switch(e1) {
		case 1:
			system("clear");
			bonus(classe);
			verHP(hp);
			verHPI(hpi);
			prints("\nVoce desafia o Troll! {Forca necessaria:13}\n");
			prints("Aperte enter para Rolar o Dado:");
			esperarEnter();
			printl("D20 de forca: ");
			usleep(700000); // pausa dramatica antes do numero
			printf("%d!\n", rolagem);

			printl("Sua forca total: ");
			usleep(700000);
			printf("%d!\n", totalf);


			if(totalf<4) {
				prints("Elion tenta atacar, mas acaba levando uma porrada em cheio.\n");
				prints("Troll: HAHAHAHAHAHHA, QUEM E O DOENDE AGORA.\n");
				hp = hp - 4;
                prints("Voce perdeu 4 de HP!\n");
                verHP(hp);
                verHPI(hpi);
                if (hpi <= 0) {
        prints("\nVoce derrotou seu adversario.");
       sucesso = 1; // vitoria 
    }
				//--hp pro elion
			} else if (totalf>=4&& totalf<=7) {
				prints("Elion tenta acertar um golpe mas acaba se machucando.\n");
				prints("Troll: Voce e forte, mas nao o suficiente.\n");
				//-hp pro elion
					hp = hp - 2;
                prints("Voce perdeu 2 de HP!\n");
				verHP(hp);
	            verHPI(hpi);
	            sucesso =0;
	            if (hpi <= 0) {
        prints("\nVoce derrotou seu adversario.");
       sucesso = 1; // vitoria 
    }
			} else if (totalf>7 && totalf<13) {
			    
				prints("Elion e o Troll entram em um embate forte, os dois se machucam.\n");
				prints("Troll: voce e mais forte do que eu imaginava.\n");
				prints("Elion: voce ainda nao viu nada.\n");
				//-hp pro elion
				    hpi = hpi -2;
					hp = hp - 2;
                prints("Voce e o Troll perderam 2 de HP!\n");
                sucesso = 0;
                verHP(hp);
                verHPI(hpi);
               sucesso =0;
                if (hpi <= 0) {
        prints("\nVoce derrotou seu adversario.");
       sucesso = 1; // vitoria 
    }
			} else if (totalf>=13 && totalf<20) {
				prints("Elion consegue desferir um enquanto o Troll.\n");
				prints("Troll: Desgracado voce vai pagar seu ");
				elion(classe);
				prints(" maldito.\n");
				hpi = hpi - 4;
				verHP(hp);
				verHPI(hpi);
				sucesso =0;
				if (hpi <= 0) {
        prints("\nVoce derrotou seu adversario.");
       sucesso = 1; // vitoria 
    }
				
			}
			else if (totalf>=20) {
				prints("Elion consegue desviar do golpe do troll, subindo em seu braço e acertando seu olho.\n");
				prints("Troll: MEU OLHO, seu ");
				elion(classe);
				prints(" Desgraçado.\n");
				hpi = hpi - 8;
				prints("Dano Critico");
                verHP(hp);
				verHPI(hpi);
				sucesso =0;
				if (hpi <= 0) {
        prints("\nVoce derrotou seu adversario.");
       sucesso = 1; // vitoria 
    }
			}
			break;
		case 2:
			system("clear");
			bonus(classe);
			verHP(hp);
			prints("\nVoce tenta convencer o Troll que voces sao amigos de longa data! {Carisma necessario:10}\n");
			prints("Aperte enter para Rolar o Dado:");
			esperarEnter();
			printl("D20 de Carisma: ");
			usleep(700000); // pausa dramatica antes do numero
			printf("%d!\n", rolagem);

			printl("Seu carisma total: ");
			usleep(700000);
			printf("%d!\n", totalc);

			if(totalc<4) {
				prints("Elion: Eu estudava com voce quando eramos pequenos.\n");
				prints("Troll: troll nunca ir na escola... troll desconfiado...\n");
				hp = hp - 3;
                prints("Voce perdeu 3 de HP!\n");
                verHP(hp);
				sucesso = 0;
				
			} else if (totalc>=4&& totalc<=9) {
				prints("Elion diz que eles costumavam a ir em dungeons juntos.\n");
				prints("Troll: troll nao lembrar de voce, desculpa.\n");
				hp = hp - 2;
                prints("Voce perdeu 2 de HP por dano emocional!\n");
                verHP(hp);
				sucesso = 0;
			} else if (totalc>9 && totalc<15) {
				prints("Elion: Eu pegava voce nos bracos quando voce era apenas um trollzinho nao se lembra do tio?\n");
				prints("Troll: ah... troll se lembra sim...(mentira)\n");
				sucesso = 1;
			} else if (totalc>15) {
				prints("Elion: Eu... Sou seu pai...\n");
				prints("Troll: Naaaaaaaaaaaao.(devido a problemas paternos o troll foge)\n");
				sucesso = 1;
			}
			break;
		case 3:
			system("clear");
	    	bonus(classe);
	    	verHP(hp);
			prints("\nVoce tenta fugir do Troll! {Vigor necessario:9}\n");
			prints("Aperte enter para Rolar o Dado:");
			esperarEnter();
			printl("D20 de Vigor: ");
			usleep(700000); // pausa dramatica antes do nC:mero
			printf("%d!\n", rolagem);

			printl("Seu vigor total: ");
			usleep(700000);
			printf("%d!\n", totalv);

			if(totalv<4) {
				prints("Elion da 3 passos antes de tropecar e cair de cara no chao.\n");
				prints("Troll: humano burro. (chuta o corpo)\n");
				//-hp elion
				hp = hp - 3;
                prints("Voce perdeu 3 de HP!\n");
                verHP(hp);
				sucesso = 0;
			} else if (totalv>=4&& totalv<=8) {
				prints("Elion quase consegue fugir porem, Troll coloca o pe pra elion tropecar.\n");
				prints("Troll: HAHAHAHa humano burro.\n");
				hp = hp - 1;
                prints("Voce perdeu 1 de HP!\n");
                verHP(hp);
				sucesso = 0;
			} else if (totalv>8 && totalv<=15) {
				prints("Elion consegue escapar por pouco das maos do troll.\n");
				prints("TROLL: COMO ESSE TRUQUE AINDA FUNCIONA NA FLORESTA.\n");
				sucesso = 1;
			} else if (totalv>15) {
		    	prints("O Troll nao consegue nem te acompanhar com os olhos.\n");
				prints("Troll: Aonde humano foi? Troll so queria brincar... \n");
				sucesso = 1;
			} 
			break;
		default:
			prints("Opcao invalida.\n");
			break;
		}
		if (sucesso==1) {
			prints("\nElion consegue passar pelo Troll e entrar na vila.\n");
		
			esperarEnter();
			system("clear");
			

		}
		else {
			prints("\nTentar denovo?\n");
			scanf("%d",&td);
			if(td==1) {
				system("clear");
				prints("Elion:Nao vou desistir tao facil...\n Troll: TROLL ESMAGA.\n");
				prints("Escolha sua acao:\n");
				prints("(1) Morra... (Desafiar Troll) {F13}\n");
				prints("(2) Nao me esmague, tenho algo a te dizer. (Tentar convencer) {C10}\n");
				prints("(3) Olha pra tras! (Sair correndo mais uma vez..) {V9}\n");
				scanf("%d", &e1);
			} else {
				prints("GAME OVER");
				return 0;
				
			}
		}
		
	    
	}	while (sucesso == 0);
	
        prints("Entrando no vila ele encontra uma renoamada ferraria chamada loja do tiao.\n");
    	prints("ao lado da loja dentro de um beco voce percebe um homem suspeito\nanalisando com mais cuidado voce percebe que ele opera um tipo de cassino clandestino\n");
    	prints("\nOdds:40%. Elion e 60%. Cassino \n");
	    prints("deseja arriscar para tentar ganhar mais dinheiro antes de entrar na ferraria?");
	    
	    scanf("%d",&e3);
	    do{
	        int rolagem = dado20();
	    if (e3 ==1){
	        system("clear");
	        		    verDin(din);
	        prints("Little Tiger: Quanto voce quer apostar? hehe\n");
	        scanf("%d", &aposta);
	        if (aposta <=din){
	            prints("Little Tiger: Se o numero for acima de 12 voce ganha, se for abaixo ou igual... hehe\n pode rolar o Dado..\n");
	            prints("Aperte enter para Rolar o Dado:");
			esperarEnter();
			printl("D20 do Little Tiger: \n");
			usleep(700000); // pausa dramatica antes do nC:mero
			printf("%d!\n", rolagem);
			if(rolagem>12){
			    prints("Parabens... se eu fosse voce eu apostaria denovo.\n");
			    din = din+aposta;
			    verDin(din);
			}else if(rolagem<=12){
			    prints("Que pena hahaha... se eu fosse voce eu tentaria recuperar.\n");
			    din = din-aposta;
			    verDin(din);
			}
	        }else{
	            prints("Little Tiger: Ta duro dorme.\n");
	        }
	    } else if (e3 ==2){
	        prints("Elion: se chama jogo de azar por um motivo... vou direto pro ferreiro.\n");
	        sucesso = 1;
	    }
	    prints("\nTentar denovo?\n");
			scanf("%d",&td);
			if (td==1){
	        sucesso = 0; }else if (td==0){
	           
	            sucesso = 1; }
     }while (sucesso == 0);
	       prints("Elion entra na loja.");
	prints("        Elion:Boa tarde, a loja ainda esta funcionando?\n");
			prints("        Tiao:Boa tarde, ainda tenho esses Itens.\n");
       verDin(din);
       verHP(hp);
	prints("    (1) Pocao de cura pequena: 5 moedas. (+3 de vida).\n");
	prints("    (2) Pocao de cura grande: 10 moedas. (+8 de vida).\n");
	prints("    (3) Espada curta enferrujada: 13 moedas. (+2 de ataque)\n");
	prints("    (4) Nao vou querer nada.\n");
     scanf("%d", &e1);
			do{
     switch(e1) {
		case 1:
			system("clear");
		if (din - 5 >= 0){
		    prints (" Elion bebe a pocao pequena de cura.\n");
		    din = din - 5;
		    hp = hp + 3;
		    verHP(hp);
		    verDin(din);
		    sucesso=0;
           } else {
		    prints ("Dinheiro insuficiente.\n");
		    sucesso=0;
		} 
		break;
		case 2:
			system("clear");
		if (din - 10 >= 0){
		    prints (" Elion bebe a pocao grande de cura.\n");
		    din = din - 10;
		    hp = hp + 8;
		    verHP(hp);
		    verDin(din);
		    sucesso=0;
		} else {
		    prints ("Dinheiro insuficiente.\n");
		    sucesso=0;
		}
		break;
		case 3:
			system("clear");
		if (din - 13 >= 0){
		    prints (" Elion:Essa espada nao parece das melhores, mas vai me ajudar na jornada.\n");
		    din = din - 13;
		    forca = forca + 2;
		    printf("Forca{f} %d / Vigor{v} %d / Stealth{s} %d / Carisma{c} %d\n", forca ,vigor ,stealth ,carisma);
		    verDin(din);
		    sucesso=0;
            }else {
		    prints ("Dinheiro insuficiente.\n");
		    sucesso=0;
		}
		break;
		case 4:
			system("clear");
		sucesso = 1;
	break;}
        if (sucesso==1) {
			prints("\nElion Sai da Ferraria e continua explorando a vila.\n");
			
			esperarEnter();
			system("clear");}
		else {
			prints("\nContinuar comprando?\n");
			scanf("%d",&td);
			if(td==1) {
				system("clear");
				
				       verDin(din);
              verHP(hp);
        	prints("    (1) Pocao de cura pequena: 5 moedas. (+3 de vida).\n");
        	prints("    (2) Pocao de cura grande: 10 moedas. (+8 de vida).\n");
        	prints("    (3) Espada curta enferrujada: 13 moedas. (+2 de ataque)\n");
        	prints("    (4) So isso obrigado.\n");
				scanf("%d", &e1);
			} else {
				sucesso==1;
			}
		}
			}while (sucesso == 0);
		prints("???:VOCE AI FOI VOCE QUEM PASSOU PELO NOSSO TROLL?\n");
		prints("Elion: Me desculpe ele nao me deixava passar...\n");
		prints("???:Perai.... ELION?\n");
		prints("Elion:Voce me conhece?\n");
		prints("Lancelot: Sou eu, Lancelot.\n");
		prints("Elion: Irmao, vim nessa vila falar justamente com voce, voce ficou sabendo? A pedra do conhecimento foi furtada.\n");
		printl("TO BE CONTINUED\n");
		
	return 0;
}
