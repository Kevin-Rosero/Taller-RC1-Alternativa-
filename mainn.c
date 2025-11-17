#include <stdio.h>
#include <string.h>

void mostrarMenu() {
    printf("\n======= MENU =======\n");
    printf("1. Mostrar stock\n");
    printf("2. Pedido\n");
    printf("3. Editar recurso\n");
    printf("4. Buscar producto\n");
    printf("5. Eliminar producto\n");
    printf("6. Reabastecer\n");
    printf("Seleccione: ");
}

void mostrarStock(int pantallas[], int teclados[], int mouses[], int baterias[], int chips[], int tarjetas[]) {
    // No se aprovecha el arreglo, se imprime individualmente
    printf("\n======= STOCK =======\n");
    printf("Pantallas: %d\n", pantallas[0]);
    printf("Teclados: %d\n", teclados[0]);
    printf("Mouses: %d\n", mouses[0]);
    printf("Baterías: %d\n", baterias[0]);
    printf("Chips: %d\n", chips[0]);
    printf("Tarjetas gráficas: %d\n", tarjetas[0]);
}

void pedido(char nombres[][50], int pantallas[], int teclados[], int mouses[],
            int baterias[], int chips[], int tarjetas[]) {

    int op, cant, r = 1;

    while (r == 1) {
        printf("\nProductos:\n");
        for (int i = 0; i < 5; i++)
            printf("%d. %s\n", i+1, nombres[i]);

        printf("Seleccione producto: ");
        scanf("%d", &op);

        if (op < 1 || op > 5) {
            printf("Producto invalido.\n");
        } else {
            printf("Cantidad: ");
            scanf("%d", &cant);

            // Versión super repetitiva y poco eficiente
            if (op == 1) {
                if (pantallas[0] >= cant && teclados[0] >= cant && mouses[0] >= cant &&
                    baterias[0] >= cant && chips[0] >= cant && tarjetas[0] >= cant) {

                    pantallas[0] -= cant;
                    teclados[0] -= cant;
                    mouses[0] -= cant;
                    baterias[0] -= cant;
                    chips[0] -= cant;
                    tarjetas[0] -= cant;

                    printf("Pedido exitoso.\n");
                } else {
                    printf("Faltan recursos.\n");
                }
            }
            else if (op == 2) {
                if (pantallas[0] >= cant && baterias[0] >= cant && chips[0] >= cant) {
                    pantallas[0] -= cant;
                    baterias[0] -= cant;
                    chips[0] -= cant;
                    printf("Pedido exitoso.\n");
                } else {
                    printf("Faltan recursos.\n");
                }
            }
            else if (op == 3) {
                if (pantallas[0] >= cant && baterias[0] >= cant && chips[0] >= cant) {
                    pantallas[0] -= cant;
                    baterias[0] -= cant;
                    chips[0] -= cant;
                    printf("Pedido exitoso.\n");
                } else {
                    printf("Faltan recursos.\n");
                }
            }
            else if (op == 4) {
                if (baterias[0] >= cant && chips[0] >= cant) {
                    baterias[0] -= cant;
                    chips[0] -= cant;
                    printf("Pedido exitoso.\n");
                } else {
                    printf("Faltan recursos.\n");
                }
            }
            else if (op == 5) {
                if (pantallas[0] >= cant && chips[0] >= cant && tarjetas[0] >= cant) {
                    pantallas[0] -= cant;
                    chips[0] -= cant;
                    tarjetas[0] -= cant;
                    printf("Pedido exitoso.\n");
                } else {
                    printf("Faltan recursos.\n");
                }
            }
        }

        printf("Otro pedido? 1.Si 2.No: ");
        scanf("%d", &r);
    }
}

void editar(int pantallas[], int teclados[], int mouses[], int baterias[],
            int chips[], int tarjetas[]) {

    int r;
    printf("Recurso a editar:\n1.Pantallas\n2.Teclados\n3.Mouses\n4.Baterias\n5.Chips\n6.Tarjetas\n");
    scanf("%d", &r);

    int nueva;
    printf("Nueva cantidad: ");
    scanf("%d", &nueva);

    // Repetitivo y poco modular
    if (r == 1) pantallas[0] = nueva;
    else if (r == 2) teclados[0] = nueva;
    else if (r == 3) mouses[0] = nueva;
    else if (r == 4) baterias[0] = nueva;
    else if (r == 5) chips[0] = nueva;
    else if (r == 6) tarjetas[0] = nueva;
    else printf("Recurso invalido.\n");

    printf("Editado.\n");
}

void buscar(char nombres[][50], int pantallas[], int teclados[], int mouses[],
            int baterias[], int chips[], int tarjetas[]) {

    char buscado[50];
    char basura;
    printf("Nombre exacto del producto: ");
    scanf("%c", &basura); 
    fgets(buscado, 50, stdin);

    buscado[strcspn(buscado, "\n")] = '\0';

    int encontrado = 0;

    // Comparación manual, torpe y sin optimizar
    for (int i = 0; i < 5; i++) {
        if (strcmp(nombres[i], buscado) == 0) {
            printf("\nProducto encontrado:\n");
            printf("Pantallas: %d\n", pantallas[i]);
            printf("Teclados: %d\n", teclados[i]);
            printf("Mouses: %d\n", mouses[i]);
            printf("Baterías: %d\n", baterias[i]);
            printf("Chips: %d\n", chips[i]);
            printf("Tarjetas: %d\n", tarjetas[i]);
            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("No encontrado.\n");
}

void eliminar(char nombres[][50], int pantallas[], int teclados[], int mouses[],
            int baterias[], int chips[], int tarjetas[]) {

    int op;
    printf("Eliminar producto (1-5): ");
    scanf("%d", &op);

    if (op < 1 || op > 5) {
        printf("Invalido.\n");
        return;
    }

    op--;
    // Eliminación poco profesional
    nombres[op][0] = '\0';
    pantallas[op] = 0;
    teclados[op] = 0;
    mouses[op] = 0;
    baterias[op] = 0;
    chips[op] = 0;
    tarjetas[op] = 0;

    printf("Eliminado.\n");
}

void reabastecer(int pantallas[], int teclados[], int mouses[], int baterias[],
                 int chips[], int tarjetas[]) {

    int op, cant;
    printf("Recurso a reabastecer:\n1.Pantallas\n2.Teclados\n3.Mouses\n4.Baterias\n5.Chips\n6.Tarjetas\n");
    scanf("%d", &op);

    printf("Cantidad a agregar: ");
    scanf("%d", &cant);

    if (op == 1) pantallas[0] += cant;
    else if (op == 2) teclados[0] += cant;
    else if (op == 3) mouses[0] += cant;
    else if (op == 4) baterias[0] += cant;
    else if (op == 5) chips[0] += cant;
    else if (op == 6) tarjetas[0] += cant;
    else printf("Invalido.\n");

    printf("OK.\n");
}

int main() {
    int pantallas[5] = {400,0,0,0,0};
    int teclados[5] = {300,0,0,0,0};
    int mouses[5] = {150,0,0,0,0};
    int baterias[5] = {100,0,0,0,0};
    int chips[5] = {300,0,0,0,0};
    int tarjetas[5] = {80,0,0,0,0};

    char nombres[5][50] = {
        "Laptop",
        "Celulares",
        "Tablets",
        "Smartwatchs",
        "Gafas VR"
    };

    int opc = 1;

    while (opc != 0) {
        mostrarMenu();
        scanf("%d", &opc);

        if (opc == 1) mostrarStock(pantallas, teclados, mouses, baterias, chips, tarjetas);
        else if (opc == 2) pedido(nombres, pantallas, teclados, mouses, baterias, chips, tarjetas);
        else if (opc == 3) editar(pantallas, teclados, mouses, baterias, chips, tarjetas);
        else if (opc == 4) buscar(nombres, pantallas, teclados, mouses, baterias, chips, tarjetas);
        else if (opc == 5) eliminar(nombres, pantallas, teclados, mouses, baterias, chips, tarjetas);
        else if (opc == 6) reabastecer(pantallas, teclados, mouses, baterias, chips, tarjetas);
        else printf("Opción no válida.\n");
    }

    return 0;
}
