interface StudentCardProps {
  nome: string;
  idade: number;
  curso: string;
  anoMatricula: number;
  mediaGeral: number;
  endereco: string;
  email: string;
  curriculo: string;
}

export default function StudentCard({
  nome,
  idade,
  curso,
  anoMatricula,
  mediaGeral,
  endereco,
  email,
  curriculo,
}: StudentCardProps) {
  return (
    <div className="bg-white p-6 rounded-xl shadow-md">
      <h2 className="text-2xl font-bold text-black/85 mb-2">{nome}</h2>
      <p className="text-gray-700">Curso: {curso}</p>
      <p className="text-gray-600">Idade: {idade}</p>
      <p className="text-gray-600">Ano de Matrícula: {anoMatricula}</p>
      <p className="text-gray-600">Endereço: {endereco}</p>
      <p className="text-gray-600">E-mail: {email}</p>
      <p className="text-gray-600">Currículo:&nbsp;  
        <a href={curriculo} target="_blank" rel="noopener noreferrer" className="text-blue-500">
          {curriculo}
        </a>
      </p>

      <p className="font-semibold text-green-600">Média Geral: {mediaGeral}</p>
    </div>
  );
}
