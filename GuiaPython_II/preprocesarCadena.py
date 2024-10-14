from typing import List
from collections import Counter
import re
def tokenizar(cadena: str, sep=" ") ->List[str]:
    """Toma una cadena de caracteres y devuelve una lista con cada uno de los elementos a partir de un separador"""
    return [token.strip() for token in cadena.split(sep)]

def minimizar(token_list:List[str]) -> List[str]:
    """Pasa a minuscula todos los tokens"""
    return [token.lower() for token in token_list]

def depurar_alfanumericos(token_list:List[str]) -> List[str]:
    """Elimina los caracteres no alfanumericos de la lista de tokens"""
    no_alfanum = r"\W+"
    return [re.sub(no_alfanum, "",token) for token in token_list]

def borrar_vacios(token_list:List[str]) -> List[str]:
    """Remueve los tokens vacios de la lista de tokens"""
    return [notNull for notNull in token_list if notNull]

def preprocesar_cadena(cadena:str, sep=" ") -> List[str]:
    tokenizado = tokenizar(cadena, sep)
    minimizado = minimizar(tokenizado)
    solo_alfanum = depurar_alfanumericos(minimizado)
    procesado = borrar_vacios(solo_alfanum)
    return procesado