<?php

$authCookie = '1c919b2d62b178f3c713bb5431c57cc1';

function create_auth_cookie($user) {
    $authKey = '8e798f0377c99bc0';
    if (!$authKey) {
        return false;
    }
    $userMd5 = md5($user, true);

    $result = '';
    for ($i = 0; $i < strlen($userMd5); $i++) {
        $result .= bin2hex(chr((ord($authKey[$i]) + ord($userMd5[$i])) % 256));
    }
    return $result;
}

$user = 'shanaehudson';
print ( create_auth_cookie($user) );
// Para user=nill -> 158f9d2563ad7a24c60eba4c2f9b7fc4
// Pra user=admin -> 59886662b2bdd5da7ac0ad4783e282f3
// Para shanae -> ffbe99abcae45362c742d0353ddd6a4e

// Recipe: SpaguettiAndChocolatePizzaWithBroccoli

?>
