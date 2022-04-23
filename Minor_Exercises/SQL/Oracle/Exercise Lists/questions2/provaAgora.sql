CREATE OR REPLACE TRIGGER verificpontos AFTER
    INSERT ON multa
    FOR EACH ROW
DECLARE
    vpontosacumulados motorista.pontosacumulados%TYPE;
BEGIN
    SELECT
        pontosacumulados
    INTO vpontosacumulados
    FROM
        motorista
    WHERE
        cnh = :new.cnh;

    IF ( ( :new.pontuacao + vpontosacumulados ) > 20 ) THEN
        UPDATE motorista
        SET
            situacao = 'S';

    END IF;

END verificpontos;